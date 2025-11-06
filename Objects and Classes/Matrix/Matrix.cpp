
#include "Matrix.h"
#define TRAVERSE_MATRIX \
    for (int i = 0; i < this->get_rows(); i++) \
        for (int j = 0; j < this->get_cols(); j++)

#define TRAVERSE_ROWS \
    for (int i = 0; i < this->get_rows(); i++)

#define TRAVERSE_COLS \
    for (int j = 0; j < this->get_cols(); j++)

Matrix::Matrix(int r, int c) : rows(0), cols(0), values(nullptr)
{
	if (r <= 0 || c <= 0) {
		std::cout << "[Matrix Error]: Invalid size\n";
		return;
	}
	rows = r; cols = c;
	values = new int* [rows];
	for (int i = 0; i < rows; ++i)
		values[i] = new int[cols]();
}

Matrix::Matrix(const Matrix& m) : rows(0), cols(0), values(nullptr) {
	*this = m;
}


void Matrix::set_rows(int r)
{
	if (r) this->rows = r;
	else rows = 0;
}

void Matrix::set_cols(int c)
{
	if (c) this->cols = c;
	else cols = 0;
}

void Matrix::set_values()
{
	this->values = nullptr;
}

int Matrix::get_rows() const
{
	return this->rows;
}

int Matrix::get_cols() const
{
	return this->cols;
}

int** Matrix::get_values()
{
	return this->values;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m) return *this;

	this->clear_matrix();
	this->set_rows(m.get_rows());
	this->set_cols(m.get_cols());
	this->values = new int* [this->get_rows()];
	TRAVERSE_ROWS {
		this->values[i] = new int[this->get_cols()];
	TRAVERSE_COLS{
		this->values[i][j] = m.values[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
	if (this->check_size(m)) {
		TRAVERSE_MATRIX{ {
				this->values[i][j] += m.values[i][j];
}}
	}
	else {
		std::cout << "\n[Matrix Error]: Matrices must be of Same Size for Addition\n";
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
	if (this->check_size(m)) {
		TRAVERSE_MATRIX{ {
				this->values[i][j] -= m.values[i][j];
} }
	}
	else {
		std::cout << "\n[Matrix Error]: Matrices must be of Same Size for Subtraction\n";
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m)
{
	if (cols != m.rows) {
		std::cout << "\n[Matrix ERROR]: Cannot multiply: " << rows << "x" << cols << " vs " << m.rows << "x" << m.cols << "\n";
		return *this;
	}

	Matrix result(rows, m.cols);
	result.clear_matrix();

	TRAVERSE_ROWS{
		for (int j = 0; j < m.cols; ++j) {
			int sum = 0;
			for (int k = 0; k < cols; ++k) {
				sum += (*this)(i, k) * m(k, j);
			}
			result(i, j) = sum;
		}
	}

	*this = result;
	return *this;
}

Matrix Matrix::operator*(const Matrix& m) const
{
	Matrix temp = *this;
	temp *= m;
	return temp;
}

Matrix& Matrix::operator*=(int n)
{
	TRAVERSE_MATRIX
	{
		(*this)(i, j) *= n;
	}
	return *this;
}

Matrix Matrix::operator*(int n) const
{
    Matrix temp = *this;
    temp *= n;
    return temp;
}

Matrix Matrix::operator+(const Matrix& m) const
{
	Matrix temp = *this;
	temp += m;
	return temp;
}

Matrix Matrix::operator-(const Matrix& m) const
{
	Matrix temp = *this;
	temp -= m;
	return temp;
}

Matrix& Matrix::operator+=(int n)
{
	TRAVERSE_MATRIX{ {
			this->values[i][j] += n;
} }
	return *this;
}

Matrix Matrix::operator+(int n) const
{
	Matrix temp = *this;
	temp+=n;
	return temp;
}

Matrix& Matrix::operator-=(int n)
{
	TRAVERSE_MATRIX{ {
			this->values[i][j] -= n;
} }
	return *this;
}

Matrix Matrix::operator-(int n) const
{
	Matrix temp = *this;
	temp -= n;
	return temp;
}

int& Matrix::operator()(int i, int j)
{
	if (i < 0 || i >= rows || j < 0 || j >= cols) {
		std::cout << "[Matrix ERROR] Index (" << i << "," << j << ") out of bounds! Size is " << rows << "x" << cols << "\n";
		static int dummy = 0;
		return dummy;
	}
	return values[i][j];
}

const int& Matrix::operator()(int i, int j) const
{
	if (i < 0 || i >= rows || j < 0 || j >= cols) {
		std::cout << "[Matrix ERROR] Index (" << i << "," << j << ") out of bounds! Size is " << rows << "x" << cols << "\n";
		static const int dummy = 0;
		return dummy;
	}
	return values[i][j];
}

void Matrix::clear_matrix()
{
	if (this->values) {
		TRAVERSE_ROWS {
			delete[] this->values[i];
			this->values[i] = nullptr;
		}
		delete[] this->values;
		this->values = nullptr;
	}
	rows = cols = 0;
}

bool Matrix::check_size(const Matrix& m) const
{
	return (this->get_rows() == m.get_rows() && this->get_cols() == m.get_cols());
}

Matrix::~Matrix()
{
	clear_matrix();
}

std::ostream& operator<<(std::ostream& os, Matrix& m)
{
	for (int i = 0; i < m.get_rows(); ++i) {
		for (int j = 0; j < m.get_cols(); ++j) {
			os << m(i, j);
			if (j + 1 < m.get_cols()) os << ' ';
		}
		os << '\n';
	}
	return os;
}