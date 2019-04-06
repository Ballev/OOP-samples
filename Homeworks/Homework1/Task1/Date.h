#ifndef __DATE_HEADER__
#define __DATE_HEADER__

#include <iostream>
#include <iomanip>

const size_t CHRISTMAS_DAY = 25;
const size_t MAX_NUMBER_OF_DAYS = 31;
const size_t NUMBER_OF_MONTHS = 12;
const size_t NUMBER_OF_DAYS = 365;

class Date {

// Constructors. We do not need to define our own Copy Constructor, operator= and Destructor
// (not using dynamic data, defaults are fine).
public:
	Date();
	Date(size_t, size_t, size_t);

// Operator to help with substracting dates.
	Date operator-(const Date&) const;

// Manipulators.
// There is validation for correct input in the setters.
public:
	void setDay(size_t);
	void setMonth(size_t);
	void setYear(size_t);
	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;

// Functionalities.
public:
	void addDays(const size_t);
	void removeDays(size_t);
	bool isLeapYear();
	size_t daysTillChristmas();
// When printing the Date setting '0' for the empty spaces of a regular Date.
	void print();
	bool isLaterThen(const Date&);

// Functions that are only used as helping functions for the class's inside processes.
private:
	// Find the days that have already passed for the given year.
	size_t findDaysPassed();
	size_t lengthOfMonth(size_t);
	size_t numberOfDaysInYear();

// Data.
private:
	size_t day;
	size_t month;
	size_t year;
};

// Function out of the class. Using overloading of "operator-".
// Substracting the date that is bigger with the date that is smaller.
Date& getDifference(const Date&, const Date&);

#endif // !__DATE_HEADER__