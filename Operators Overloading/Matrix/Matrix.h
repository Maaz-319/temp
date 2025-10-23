#pragma once
#include<iostream>
class Matrix
{
	int rows;
	int columns;
	int* values;
public:

	Matrix(int rows, int columns);
	Matrix() = default;
	~Matrix();

	Matrix(const Matrix& m);

	Matrix& copyFrom(const Matrix& m);
	void clear();

	Matrix& operator=(const Matrix& m);
	Matrix operator+=(const Matrix& m);
	Matrix operator-=(const Matrix& m);
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	bool operator<(const Matrix& m);
	bool operator==(const Matrix& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

