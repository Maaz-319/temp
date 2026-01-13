#include <cstring>
class Book
{
    char *title;
    char *author;
    void copyFrom(const Book &b)
    {
        title = new char[strlen(b.title) + 1];
        author = new char[strlen(b.author) + 1];
        strcpy(title, b.title);
        strcpy(author, b.author);
    }

public:
    Book(const Book &b)
    {
        copyFrom(b);
    }

    Book &operator=(const Book &b)
    {
        delete[] title;
        delete[] author;
        copyFrom(b);
        return *this;
    }

    ~Book()
    {
        delete[] title;
        delete[] author;
    }
};