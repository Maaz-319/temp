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