#include <iostream>

#include "Teacher.h"
#include "Student.h"

int main()
{
	Teacher t("Ivan", 34, "Language High School", "Maths");
	Student s("Gosho", 15, "Maths University", "Informatics", 45123);
	Student s1(s);
	s.print();
	s1.print();
	t.print();
	t.changeSubject("Algebra");
	t.print();
	return 0;
}
