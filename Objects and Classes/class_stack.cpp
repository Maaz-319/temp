class Stack
{
    int *arr, top, capacity;

public:
    Stack(int size = 2)
    {
        capacity = size;
        arr = new int[capacity];
        top = 0;
    }
    void push(int val)
    {
        if (top == capacity)
        {
            int *temp = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            capacity *= 2;
        }
        arr[top++] = val;
    }
    void pop()
    {
        if (top >= 0)
            top--;
    }
    int peek() const
    {
        if (top > 0)
            return arr[top - 1];
        return -1;
    }
    void clear()
    {
        delete[] arr;
        top = 0;
        capacity = 2;
        arr = new int[capacity];
    }
    bool isEmpty() const { return top == 0; }
    ~Stack() { delete[] arr; }
};