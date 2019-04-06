#include "Date.h"

Date::Date() : day(1), month(1), year(2000)
{}

Date::Date(size_t _day, size_t _month, size_t _year) {

	setDay(_day);
	setMonth(_month);
	setYear(_year);
}

Date Date::operator-(const Date & date2) const {

	Date result;
	result.year = year - date2.getYear();
	
	if (date2.getMonth() > month) {

		result.setMonth(NUMBER_OF_MONTHS - (date2.getMonth() - month));
		--result.year;
	}

	else
		result.setMonth(month - date2.getMonth());

	if (date2.getDay() > day) {

		result.setDay( result.lengthOfMonth(result.getMonth()) - (date2.getDay() - day));
		--result.month;
	
		if (result.month == 0) {

			--result.year;
			result.month = NUMBER_OF_MONTHS;
		}
	}

	else
		result.setDay(day - date2.getDay());

	return result;
}

void Date::setDay(size_t _day) {

	if (_day > MAX_NUMBER_OF_DAYS || _day <= 0 || _day > lengthOfMonth(month)) {

		std::cerr << "You have chosen an unexisting day!" << std::endl;
		return;
	}

	day = _day;
}

void Date::setMonth(size_t _month) {

	if (_month > NUMBER_OF_MONTHS || _month <= 0) {

		std::cerr << "You have chosen an unexisting month!" << std::endl;
		return;
	}

	month = _month;
}

void Date::setYear(size_t _year) {

	if (year < 0) {

		std::cerr << "You have chosan a negative year! Choose other date, please!" << std::endl;
		return;
	}

	year = _year;
}

size_t Date::getDay() const {

	return day;
}

size_t Date::getMonth() const {

	return month;
}

size_t Date::getYear() const {

	return year;
}

void Date::addDays(size_t newDays) {

	size_t daysPassed = findDaysPassed();             
	size_t remainingDays = numberOfDaysInYear() - daysPassed; 
	size_t tempDays = 0;
	
	if (newDays <= remainingDays) {

		tempDays = newDays + daysPassed; 
	}

	else {

		newDays -= remainingDays;
		++year;
		size_t lengthOfNewYear = numberOfDaysInYear();
		while (newDays >= lengthOfNewYear) {

			newDays -= lengthOfNewYear;
			++year;
			lengthOfNewYear = numberOfDaysInYear();
		}

	    tempDays = newDays;
	}

	size_t i = 1;

	for (i; i <= NUMBER_OF_MONTHS; ++i) {

		if (tempDays <= lengthOfMonth(i)) 
			break;
		
		tempDays = tempDays - lengthOfMonth(i);
	}

	day = tempDays; // 2
	month = i;      // 1

	print();
}

void Date::removeDays(size_t daysToSubstract) {

	size_t daysPassed = findDaysPassed();
	size_t tempDays = 0;

	if (daysToSubstract <= daysPassed) {

		tempDays = daysPassed - daysToSubstract;
	}
	
	else {
		
		do {

			--year;
			daysToSubstract = daysToSubstract - daysPassed;
			daysPassed = numberOfDaysInYear();
			
		} while (daysToSubstract > daysPassed);
		
		tempDays = daysToSubstract;
	}

	size_t i = 1;
	for (i; i <= NUMBER_OF_MONTHS; ++i) {

		if (tempDays <= lengthOfMonth(i))
			break;

		else
			tempDays -= lengthOfMonth(i);
	}

	month = i;
	day = tempDays;
	
	print();
}

bool Date::isLeapYear() {                                // Calculating, if the year is leap. 
                                                         // The additional check with '%100' amd '%400' is to remove the years that are not leap
	                                                     // but can be concluded as leap because of the '%4' condition.
	
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;

	return false;
}

// Days till Christmas will be calculated for the year given to the function. The given year's Christmas is the closest one.
size_t Date::daysTillChristmas() {

	size_t remainingDays = 0;
	
	for (size_t i = month + 1; i <= NUMBER_OF_MONTHS; ++i) {

		remainingDays += lengthOfMonth(i);
	}

	remainingDays += ( lengthOfMonth(month) - day - 6);

	return remainingDays;
}

void Date::print() {

	std::cout << std::setfill('0') << std::setw(2) << day << ":" << std::setfill('0') << std::setw(2)
		<< month << ":" << std::setfill('0') << std::setw(4) << year << std::endl;
}

bool Date::isLaterThen(const Date & date2) {               // If true, our date is later in the calendar then date2.

	if (year < date2.year || (year == date2.year && month < date2.month)
		|| (year == date2.year && month == date2.month && day < date2.day))
		return false;

	return true;
}

size_t Date::findDaysPassed() {

	size_t daysPassed = 0;
	
	for (size_t i = month; i >= 1; --i) {

		daysPassed += lengthOfMonth(i);
	}

	daysPassed -= (lengthOfMonth(month) - day);
	
	return daysPassed;
}

size_t Date::lengthOfMonth(size_t _month) {

	size_t daysInMonth = 0;
	
	if (_month == 2) {
		
		if (isLeapYear()) 
			daysInMonth = 29;
		
		else
			daysInMonth = 28;
	}
	
	else if (_month == 4 || _month == 6 ||
		     _month == 9 || _month == 11) 
		daysInMonth = 30;
	
	else
		daysInMonth = MAX_NUMBER_OF_DAYS;
	
	return daysInMonth;
}

size_t Date::numberOfDaysInYear() {

	return isLeapYear() ? (NUMBER_OF_DAYS + 1) : (NUMBER_OF_DAYS);
}

Date & getDifference(const Date & date1, const Date & date2) {

	Date substractedDate;
	
	if (date2.getYear() >= date1.getYear())
		substractedDate = date2.operator-(date1);

	else
		substractedDate = date1.operator-(date2);

	return substractedDate;
}
