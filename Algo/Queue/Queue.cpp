template <typename dataType>
class Queue
{
    dataType *arr;
    int front, rear, count, capacity;

public:
    Queue(int size = 100)
    {
        if (size <= 0)
            throw "Size must be greater than 0";

        capacity = size;
        arr = new dataType[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == capacity;
    }

    void push(const dataType &value)
    {
        if (isFull())
            throw "Queue is full";

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    dataType pop()
    {
        if (isEmpty())
            throw "Queue is empty";

        dataType value = arr[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    dataType peek() const
    {
        if (isEmpty())
            throw "Queue is empty";

        return arr[front];
    }
};
