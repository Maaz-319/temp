#include "Complex.h"
#include <iostream>
int main() {
	Complex c1(-1, 4), c2(1, -6), c3 = c1+c2;
	std::cout << (c1 << c1); std::cout << std::endl;
	std::cout << (c2 << c2); std::cout << std::endl;
	std::cout << (c3 << c3); std::cout << std::endl;
}