#pragma once
#include <string>

class Complex {
	int real;
	int imaginary;

public:
	Complex(int, int);
	
	void set_real(int);
	void set_imaginary(int);

	int get_real();
	int get_imaginary();

	void copy(const Complex&);

	Complex(const Complex&);
	Complex& operator=(const Complex&);
	Complex operator+(const Complex&);
	std::string operator<<(const Complex&);
};