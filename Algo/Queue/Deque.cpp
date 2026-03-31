template <typename dataType>
class Deque
{
    dataType *arr;
    int front;
    int back;
    int capacity;
    int count;

    void expand()
    {
        int oldCapacity = capacity;
        capacity *= 2;

        dataType *temp = new dataType[capacity];

        for (int i = 0; i < count; i++)
            temp[i] = arr[(front + i) % oldCapacity];

        delete[] arr;
        arr = temp;

        front = 0;
        back = count - 1;
    }

public:
    Deque(int capacity = 7)
    {
        if (capacity < 1)
            capacity = 7;
        this->capacity = capacity;
        front = 0;
        back = -1;
        count = 0;
        arr = new dataType[capacity];
    }

    int size() const { return count; }
    bool empty() const { return count == 0; }
    bool full() const { return count == capacity; }

    void push_back(dataType val)
    {
        if (full())
            expand();
        back = (back + 1) % capacity;
        arr[back] = val;
        count++;
    }

    void push_front(dataType val)
    {
        if (full())
            expand();
        front = (front - 1 + capacity) % capacity;
        arr[front] = val;
        count++;
    }

    dataType peek_front()
    {
        if (empty())
            throw("Empty Queue");
        return arr[front];
    }

    dataType peek_back()
    {
        if (empty())
            throw("Empty Queue");
        return arr[back];
    }

    dataType pop_front()
    {
        if (empty())
            throw("Empty Queue");
        dataType val = peek_front();
        front = (front + 1) % capacity;
        count--;
        return val;
    }

    dataType pop_back()
    {
        if (empty())
            throw("Empty Queue");
        dataType val = peek_back();
        back = (back - 1 + capacity) % capacity;
        count--;
        return val;
    }

    void clear(bool free_memory = false)
    {
        if (free_memory)
        {
            delete[] arr;
            capacity = 7;
            arr = new dataType[capacity];
        }
        front = 0;
        count = 0;
        back = -1;
    }

    Deque(const Deque &) = delete;
    Deque &operator=(const Deque &) = delete;

    ~Deque()
    {
        delete[] arr;
    }
};