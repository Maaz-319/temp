#include "Book.cpp"

class Library {
    int count;
    Book *books;
public:
    Library() {
        count = 0;
        books = new Book[10];
    }

    void addBook(const Book& b) {
        if(count<10){
            books[count++] = b;
        }
    }

    void displayBooks(){
        cout << "--- Library Books ---";
        for(int i=0; i<count; i++){
            cout << "\nTitle: " << books[i].title << ", Author: " << books[i].author;
        }
    }

    ~Library() {
        delete[] books;
    }
};

int main(){
    Library lib;
    lib.addBook(Book("C++ Basics", "Bjarne"));
    lib.addBook(Book("Algorithms", "CLRS"));
    lib.displayBooks();
    return 0;
}