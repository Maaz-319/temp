#include "Matrix.h"

int main() {
	Matrix m1(3, 3), m4(2, 5);
	std::cout << m1 << std::endl;

	Matrix m2 = m1, m3(1, 2);
	std::cout << m2 << std::endl;
	
	m3 = m2;
	std::cout << m3 << std::endl;

	std::cout << (m3 -= m4) << std::endl;
	std::cout << m3 << std::endl;
	std::cout << m4 << std::endl;
	return 0;
}