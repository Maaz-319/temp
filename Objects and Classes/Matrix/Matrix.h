#pragma once
#include<iostream>

class Matrix
{
	int rows;
	int cols;
	int** values;

public:
	Matrix(int r, int c);
	Matrix(const Matrix& m);

	void set_rows(int r);
	void set_cols(int c);
	void set_values();

	int get_rows() const;
	int get_cols() const;
	int** get_values();
	
	Matrix& operator=(const Matrix& m);
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix& operator*=(const Matrix& m);
	Matrix operator*(const Matrix& m) const;
	Matrix operator+(const Matrix& m) const;
	Matrix operator-(const Matrix& m) const;
	Matrix& operator+=(int n);
	Matrix operator+(int n) const;
	Matrix& operator-=(int n);
	Matrix operator-(int n) const;
	Matrix& operator*=(int n);
	Matrix operator*(int n) const;
	int& operator()(int i, int j);
	const int& operator()(int i, int j) const;

	friend std::ostream& operator<<(std::ostream& os, Matrix& m);

	void clear_matrix();
	bool check_size(const Matrix &m) const;

	~Matrix();
};

