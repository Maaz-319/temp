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