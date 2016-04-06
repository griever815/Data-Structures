#pragma once

#include "GPAInterface.h"
#include "Student.h"
#include <fstream>
#include <sstream>



class GPA : public GPAInterface
{
private:

	map<unsigned long long int, StudentInterface*> meMap;
	set<StudentInterface*, Comparator> meSet;



public:

	GPA();
	~GPA();


	map<unsigned long long int, StudentInterface*> getMap();
	set<StudentInterface*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();


};