#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

class VectorWithIndex {
private:
    int* arr;
    int capacity;
    int currentSize;

public:
    VectorWithIndex(int cap) {
        capacity = cap;
        arr = new int[capacity];
        currentSize = 0;
    }

    void insert(int value) {
        if (currentSize < capacity) {
            arr[currentSize] = value;
            currentSize++;
        }
    }

    ~VectorWithIndex() {
        delete[] arr;
    }
};



class VectorWithoutIndex {
private:
    int* arr;
    int capacity;

public:
    VectorWithoutIndex(int cap) {
        capacity = cap;
        arr = new int[capacity];

        for (int i = 0; i < capacity; i++)
            arr[i] = -1;
    }

    void insert(int value) {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] == -1) {
                arr[i] = value;
                break;
            }
        }
    }

    ~VectorWithoutIndex() {
        delete[] arr;
    }
};

int main() {
    for (int N = 1000; N<100000; N=N*5){
        cout << "\nFor N=" << N<<endl;

    auto start1 = high_resolution_clock::now();
    VectorWithIndex v1(N);
    for (int i = 0; i < N; i++)
        v1.insert(i);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    VectorWithoutIndex v2(N);
    for (int i = 0; i < N; i++)
        v2.insert(i);
    auto end2 = high_resolution_clock::now();

    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    auto duration2 = duration_cast<milliseconds>(end2 - start2);

    cout << "Vector with index time: "
         << duration1.count() << " ms" << endl;

    cout << "Vector without index time: "
         << duration2.count() << " ms" << endl;}

    return 0;
}
