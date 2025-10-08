#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>

int *create_array(int s)
{
    if (s < 1) return nullptr;
    int *ptr = new int[s];
    return ptr;
}

int *delete_array(int *ptr, int *size) { *size = 0; delete[] ptr; return nullptr; }

void copy_array(const int *source, int *dest, int source_size, int dest_size)
{
    if (source_size <= 0 || dest_size <= 0) return;
    for (int i = 0; i < std::min(source_size, dest_size); i++) dest[i] = source[i];
}

void sort_array(int *arr, int size)
{
    if (size <= 0) return;
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j) if (arr[j] < arr[min_idx]) min_idx = j;
        std::swap(arr[i], arr[min_idx]);
    }
}

void print_array(const int *arr, int size)
{
    if (size <= 0) return;
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void print_array_to_file(std::string filename, const int *arr, int size)
{
    if (size <= 0) return;
    std::ofstream file(filename + ".txt");
    for (int i = 0; i < size; i++) file << arr[i] << " ";
    file.close();
}

void fill_array_random(int *arr, int size, int minValue, int maxValue)
{
    if (size <= 0) return;
    srand(time(NULL));
    for (int i = 0; i < size; i++) arr[i] = minValue + rand() % (maxValue - minValue);
}

const int *array_get(const int *arr, int size, int index)
{
    if (size <= 0) return nullptr;
    if (index < size) return arr + index;
    else return nullptr;
}

void array_set(int *arr, int size, int index, int value)
{
    if (size <= 0) return;
    if (index < size) arr[index] = value;
    else std::cerr << "\n[INDEX OUT OF BOUND] Error: The provided index is greater than array size\n";
}

int array_sum(const int *arr, int size)
{
    if (size <= 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

int array_min(const int *arr, int size)
{
    if (size <= 0) return -1;
    int min_num = arr[0];
    for (int i = 1; i < size; i++) min_num = std::min(min_num, arr[i]);
    return min_num;
}

int array_max(const int *arr, int size)
{
    if (size <= 0) return -1;
    int max_num = arr[0];
    for (int i = 1; i < size; i++) max_num = std::max(max_num, arr[i]);
    return max_num;
}

void my_swap(int* a, int* b) { return std::swap(*a, *b); }