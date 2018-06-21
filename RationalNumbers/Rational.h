#ifndef __RATIONAL_HEADER__
#define __RATIONAL_HEADER__


#include <iostream>

class Rational
{

public:

	Rational(int, int);
	Rational& operator=(const Rational&);

public:

	void simplify();

public:

	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);

	friend const Rational operator+(const Rational&, const Rational&);
	friend const Rational operator-(const Rational&, const Rational&);
	friend const Rational operator*(const Rational&, const Rational&);
	friend const Rational operator/(const Rational&, const Rational&);

	// ++i
	Rational& operator++(); 
	// i++
	const Rational operator++(int);
	// --i
	Rational& operator--(); 
	// i--
	const Rational operator--(int);

	friend bool operator==(const Rational&, const Rational&);
	friend bool operator!=(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);
	friend bool operator>(const Rational&, const Rational&);
	friend bool operator>=(const Rational&, const Rational&);
	friend bool operator<=(const Rational&, const Rational&);

	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);

	double asDouble() const;


private:

	int numerator;
	int denominator;

};

#endif // !__RATIONAL_HEADER__