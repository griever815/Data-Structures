#pragma once

#include "StudentInterface.h"
#include <sstream>
#include <iostream>
#include <iomanip>



class Student : public StudentInterface
{
private:

	unsigned long long int ID;
	string Name;
	string Address;
	string PhoneNumber;
	double GPA;
	double runningGPA;
	int courseCount;
	////Make sure to use setPrecision(2) with GPA.


	string Class;
	string Grade;


public:

	Student(unsigned long long int newID, string newName, string newAddress, string newPhone);
	~Student();

	unsigned long long int getID();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();





};

