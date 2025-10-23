#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
	if (rows > 1 and columns > 1)
	{
		this->rows = rows;
		this->columns = columns;
	}
	else 
	{
		this->rows = 1;
		this->columns = 1;
	}
	this->values = new int[rows * columns];
	for (int i = 0; i < this->rows * columns; i++) values[i] = i;
}

Matrix::~Matrix()
{
	clear();
}

Matrix::Matrix(const Matrix& m)
{
	this->values = new int[m.rows * m.columns];
	copyFrom(m);
}

Matrix& Matrix::copyFrom(const Matrix& m)
{
	this->rows = m.rows;
	this->columns = m.columns;
	for (int i = 0; i < this->rows * this->columns; i++) {
		this->values[i] = m.values[i];
	}
	return *this;
}

void Matrix::clear()
{
	delete[] values;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	clear();
	this->values = new int[m.rows * m.columns];
	copyFrom(m);
	return *this;
}

Matrix Matrix::operator+=(const Matrix& m)
{
	if (*this == m) {
		for (int i = 0; i < this->rows * this->columns; i++)
		{
			this->values[i] += m.values[i];
		}
		return *this;
	}
	return Matrix(1, 1);
}

Matrix Matrix::operator-=(const Matrix& m)
{
	if (*this == m) {
		for (int i = 0; i < this->rows * this->columns; i++)
		{
			this->values[i] -= m.values[i];
		}
		return *this;
	}
	return Matrix(1, 1);
}

Matrix Matrix::operator+(const Matrix& m)
{
	Matrix temp = *this;
	temp += m;
	return temp;
}

Matrix Matrix::operator-(const Matrix& m)
{
	Matrix temp = *this;
	temp -= m;
	return temp;
}

bool Matrix::operator<(const Matrix& m)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < this->rows * this->columns; i++) {
		sum1 += this->values[i];
	}
	for (int i = 0; i < m.rows * m.columns; i++) {
		sum2 += m.values[i];
	}
	return sum1 < sum2;
}

bool Matrix::operator==(const Matrix& other) const
{
	return rows == other.rows && columns == other.columns;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.columns; j++) {
			os << m.values[i * m.columns + j]<<" ";
		}
		os << "\n";
	}
	return os;
}
