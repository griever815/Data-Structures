#include "Student.h"

using namespace std;


Student::Student(unsigned long long int newID, string newName, string newAddress, string newPhone)
{
	ID = newID;
	Name = newName;
	Address = newAddress;
	PhoneNumber = newPhone;
	GPA = 0.00;
	courseCount = 0;
	runningGPA = 0.00;
}

Student::~Student()
{

}

unsigned long long int Student::getID()
{
	/*		
	* getID()
	*
	* Returns the ID of the Student.
	*/

	return ID;
}

string Student::getName()
{
	/*
	* getName()
	*
	* Returns the name of the Student
	*/

	return Name;
}

string  Student::getGPA()
{
	/*
	* getGPA()
	*
	* Returns the string representation of the Student's GPA.
	*/

	

	stringstream ss;
	ss << fixed << setprecision(2) << GPA;

	return ss.str();

}

void Student::addGPA(double classGrade)
{
	/*
	* addGPA()
	*
	* Incorporates the given course grade into the Student's overall GPA.
	*/


	runningGPA += classGrade;
	courseCount++;
	GPA = runningGPA / courseCount;
}

string Student::toString()
{
	/*
	* toString()
	*
	* The student object will be put into string representation. Student info will be
	* ordered ID, name, address, phone number, and GPA. Each piece of information will
	* be on its own line. GPA will not have a newline following it and the precision 
	* of the GPA will be rounded to two decimal places. For example,
	* 
	* 123456789
	* Ben Thompson
	* 17 Russell St, Provo, UT 84606
	* 555-555-5555
	* 3.12
	* 
	* Returns a string representation of the student object There is no trailing new line.
	*/
	stringstream ss;

	ss << ID << endl << Name << endl << Address << endl << PhoneNumber << endl << fixed << setprecision(2) << GPA;

	string toReturn = ss.str();



	return toReturn;

}