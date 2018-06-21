#include "Rational.h"



Rational::Rational(int _numerator, int _denominator) : numerator(_numerator)
{
	if (_denominator == 0)
	{
		std::cerr << "Can not have denominator = 0! We will give it value 1 for you.\n";
		denominator = 1;
	}
	else
		denominator = _denominator;
}


Rational & Rational::operator=(const Rational & other)
{
	if (this != &other)
	{
		numerator = other.numerator;
		denominator = other.denominator;
	}
	
	return *this;
}

void Rational::simplify()
{
	for (int i = 2; i < numerator; i++)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
		if (i == denominator)
			break;
	}
}

Rational & Rational::operator+=(const Rational & other)
{
	numerator = numerator * other.denominator +
				other.numerator * denominator;
	denominator *= other.denominator;
	
	return *this;
}

Rational & Rational::operator-=(const Rational & other)
{
	numerator = numerator * other.denominator -
		other.numerator * denominator;
	denominator *= other.denominator;

	return *this;
}

Rational & Rational::operator*=(const Rational & other)
{
	numerator *= other.numerator;
	denominator *= other.denominator;

	return *this;
}

Rational & Rational::operator/=(const Rational & other)
{
	numerator = other.denominator;
	denominator = other.numerator;

	return *this;
}

Rational & Rational::operator++()
{
	numerator += denominator;
	return *this;
}

const Rational Rational::operator++(int)
{
	Rational temp(*this);
	this->operator++();

	return temp;
}

Rational & Rational::operator--()
{
	numerator -= denominator;
	return *this;
}

const Rational Rational::operator--(int)
{
	Rational temp(*this);
	this->operator--();

	return temp;
}

double Rational::asDouble() const
{
	return static_cast<double>(numerator) / denominator;
}

const Rational operator+(const Rational & lhs, const Rational & rhs)
{
	return Rational(lhs) += rhs;
}

const Rational operator-(const Rational & lhs, const Rational & rhs)
{
	return Rational(lhs) -= rhs;
}

const Rational operator*(const Rational & lhs, const Rational & rhs)
{
	return Rational(lhs) *= rhs;
}

const Rational operator/(const Rational & lhs, const Rational & rhs)
{
	return Rational(lhs) /= rhs;
}

bool operator==(const Rational & lhs, const Rational & rhs)
{
	return  (lhs.numerator * rhs.denominator == lhs.denominator * rhs.numerator);
}

bool operator!=(const Rational & lhs, const Rational & rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Rational & lhs, const Rational & rhs)
{
	return (lhs.numerator * rhs.denominator < lhs.denominator * rhs.numerator);
}

bool operator>(const Rational & lhs, const Rational & rhs)
{
	return rhs < lhs;
}

bool operator>=(const Rational & lhs, const Rational & rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const Rational & lhs, const Rational & rhs)
{
	return !(lhs > rhs);
}

std::ostream & operator<<(std::ostream & ofs, const Rational & r)
{
	return ofs << r.numerator << "/" << r.denominator;
}

std::istream & operator>>(std::istream & ifs, Rational & r)
{
	return ifs >> r.numerator >> r.denominator;
}
