#include <iostream>

using namespace std;

void *allocate(int size);
void deallocate(void *ptr);
void initialize_pool();
void attempt_defragment();
void print_pool();

struct Header
{
    int size;
    bool free;
    Header *next;
};

const int POOL_SIZE = 1024;
char *pool = new char[POOL_SIZE];
Header *head;

void initialize_pool()
{
    head = (Header *)pool;
    head->size = POOL_SIZE - sizeof(Header);
    head->free = true;
    head->next = nullptr;
}

void *allocate(int size)
{
    Header *current = head;
    while (current != nullptr)
    {
        if (current->free && current->size >= size)
        {
            if (current->size > size + sizeof(Header))
            {
                Header *new_block = (Header *)((char *)current + sizeof(Header) + size);
                new_block->size = current->size - size - sizeof(Header);
                new_block->free = true;
                new_block->next = current->next;

                current->size = size;
                current->next = new_block;
            }
            current->free = false;
            return (char *)current + sizeof(Header);
        }
        current = current->next;
    }
    return nullptr;
}

void deallocate(void *ptr)
{
    if (!ptr) return;
    Header *block = (Header *)((char *)ptr - sizeof(Header));
    block->free = true;
    attempt_defragment();
}

void attempt_defragment()
{
    Header *current = head;
    while (current && current->next)
    {
        if (current->free && current->next->free)
        {
            current->size += sizeof(Header) + current->next->size;
            current->next = current->next->next;
        }
        else current = current->next;
    }
}

void print_pool()
{
    Header *current = head;
    int i = 0;
    cout << "\n--- Pool Layout ---\n";
    while (current)
    {
        cout << "Block " << i++ << " | size: " << current->size << " | free: " << (current->free ? "yes" : "no") << " | addr: " << (void *)current << endl;
        current = current->next;
    }
}

int main()
{
    initialize_pool();
    print_pool();

    cout << "\nAllocating 100 bytes...\n";
    void *a = allocate(100);
    print_pool();

    cout << "\nAllocating 200 bytes...\n";
    void *b = allocate(200);
    print_pool();

    cout << "\nDeallocating first block...\n";
    deallocate(a);
    print_pool();

    cout << "\nDeallocating second block (should merge)...\n";
    deallocate(b);
    print_pool();

    delete[] pool;
    return 0;
}