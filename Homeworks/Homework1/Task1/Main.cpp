#include <iostream>
#include <iomanip>

#include "Date.h"

int main() {

	Date date1;
	Date date2(2, 2, 2017);
	Date date3(30, 11, 2018);

	date2.addDays(750);
	std::cout << date1.daysTillChristmas() << std::endl;
	std::cout << date1.isLaterThen(date2) << std::endl;
	date1.addDays(3);
	date3.removeDays(15);
	
	Date result = getDifference(date1, date3);
	result.print();

	return 0;

}
