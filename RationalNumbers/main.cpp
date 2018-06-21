#include <iostream>

#include "Rational.h"

int main()
{

	Rational r(5, 6);
	Rational r2(7, 5);
	std::cout << r + r2 << "\n";
	if (r < r2)
	{
		std::cout << "Horey!\n";
	}
	Rational r3(8, 14);
	std::cout << r3 << "\n";
	r3 += r;
	r--;
	std::cout << r3 << "   " << r << "\n";
	return 0;
}
