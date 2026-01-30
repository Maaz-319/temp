template <typename dataType>
class Stack
{
    dataType *list;
    int pos, size;
    void resize()
    {
        size *= 2;
        dataType *temp = list;
        list = new dataType[size];
        for (int i = 0; i < pos; i++)
            list[i] = temp[i];
        delete[] temp;
    }

public:
    Stack(int size = 100)
    {
        if (size < 1)
            throw("Size must be greater than 0");
        this->size = size;
        pos = 0;
        list = new dataType[this->size];
    }
    Stack(const Stack &o)
    {
        this->size = o.getSize();
        this->pos = o.getPos();
        this->list = new dataType[this->size];
        for (int i = 0; i < this->pos; i++)
            this->list[i] = o[i];
    }
    void push(dataType val)
    {
        if (this->pos == this->size)
            resize();
        list[pos++] = val;
    }
    dataType &top()
    {
        if (isEmpty())
            throw("Empty Stack");
        return list[pos - 1];
    }
    dataType pop()
    {
        if (isEmpty())
            throw("Empty Stack");
        return list[--pos];
    }
    bool isEmpty()
    {
        return (this->pos == 0);
    }
    const dataType &operator[](int idx) const
    {
        if (idx < 0 || idx > pos)
            throw("Index out of Range");
        return list[idx];
    }
    int getSize() { return this->size; }
    int getPos() { return this->pos; }
    ~Stack() { delete[] list; }
};