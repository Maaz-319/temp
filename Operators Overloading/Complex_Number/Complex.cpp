#include "Complex.h"

Complex::Complex(int real, int imaginary)
{
	set_real(real);
	set_imaginary(imaginary);
}

void Complex::set_real(int real)
{
	this->real = real;
}

void Complex::set_imaginary(int imaginary)
{
	this->imaginary = imaginary;
}
int Complex::get_real()
{
	return this->real;
}

int Complex::get_imaginary()
{
	return this->imaginary;
}

void Complex::copy(const Complex& c)
{
	this->real = c.real;
	this->imaginary = c.imaginary;
}

Complex::Complex(const Complex& c)
{
	this->copy(c);
}

Complex& Complex::operator=(const Complex& c)
{
	this->copy(c);
	return *this;
}

Complex Complex::operator+(const Complex& c)
{
	Complex temp = *this;
	temp.set_real(this->real + c.real);
	temp.set_imaginary(this->imaginary + c.imaginary);
	return temp;
}

std::ostream& Complex::operator<<(std::ostream& os, const Complex& c) {
	os << c.get_real();
	if (c.get_imaginary() < 0) os << " - " << -c.get_imaginary() << 'i';
	else                       os << " + " << c.get_imaginary() << 'i';
	return os;
}

