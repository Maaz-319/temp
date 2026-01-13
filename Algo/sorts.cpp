#include <iostream>
#include <utility>
using namespace std;

int bubble_sort(int*arr) {
    int count = 0;
    for (int i=0; i<10; i++){
        for(int j=0; j<9; j++){
            if (arr[i] < arr[j]) swap(arr[i], arr[j]); count++;
        }
    }
    return count;
}

int selection_sort(int*arr) {
    int count = 0;
    for (int i=0; i<9; i++){
        int min = i;
        for(int j=i+1; j<10; j++){
            count++;
            if (arr[min] > arr[j]) min = j;
        }
        swap(arr[min], arr[i]);
    }
    
    return count;
}

int insertion_sort(int*arr){
    int count = 0, j;
    for (int i=1; i<10; i++){
        int temp = arr[i];
        for(j=i-1; j>=0&&arr[j]>temp; j--){
            arr[j+1] = arr[j];
            count ++;
        }
        arr[j+1] = temp;
    }
    return count;
}

void print(int *arr) {
    cout << "\n";
    for (int i=0; i<10; i++) cout << arr[i] << " ";
}

int main() {
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    print(arr);
    int bubble = bubble_sort(arr);
    print(arr);
    cout <<endl <<bubble;
    cout << "\n==============\n";
    int arr2[10] = {10,9,8,7,6,5,4,3,2,1};
    print(arr2);
    int selection = selection_sort(arr2);
    print(arr2);
    cout <<endl <<selection;
    cout << "\n==============\n";
    int arr3[10] = {10,9,8,7,6,5,4,3,2,1};
    print(arr3);
    int insertion = insertion_sort(arr3);
    print(arr3);
    cout <<endl <<insertion;
    return 0;
}