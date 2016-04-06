#include "GPA.h"
#include <iostream>

using namespace std;

GPA::GPA()
{

}

GPA::~GPA()
{
	clear();
}

map<unsigned long long int,StudentInterface*> GPA::getMap()
{
	/*
	* getMap()
	* 
	* Returns the map storing the student information. 
	* The key of the map should be the student ID.
	*/

	return meMap;
}

set<StudentInterface*,Comparator> GPA::getSet()
{
	/*
	* getSet()
	*
	* Returns the set storing the student information.
	*/

	return meSet;
}

bool GPA::importStudents(string mapFileName, string setFileName)
{
	/*
	* importStudents()
	*
	* Read in and parse through the given files. Each part of an entry in a
	* file is given on a separate line in the file. Student ID is first, name is
	* second, address is third, and phone is last. There are no blank lines between
	* students. The following is an example file:
	*
	*	 5291738600
	* 	 Dick B. Smith
	* 	 879 Maple Road, Centralia, Colorado 24222
	* 	 312-000-1000
	* 	 9251738707
	*	 Harry C. Anderson
	*	 635 Main Drive, Midville, California 48444
	* 	 660-050-2200
	*
	* If a valid file is given, the new Students should be added to the existing
	* map and set. 
	*
	* If an invalid file name is given or if there is a missing entry for a student, 	
	* return false. Duplicate student ID numbers and duplicate students will not be 
	* tested for. There will never be a student that exists in the map and set. If 
	* the function returns false, then no changes should have been made to the 
	* existing map or set. 
	*
	* The key of the map should be the student ID.
	*
	* Returns false if an invalid filename is given or if there is a missing entry for a
	* student, otherwise true.
	*/

	
	map<unsigned long long int, StudentInterface*> tempMap;
	set<StudentInterface*, Comparator> tempSet;
	int countMap = -1;
	int countSet = -1;


	ifstream studentImport;
	studentImport.open(mapFileName.c_str());
	if (!studentImport.fail())
	{
		while(!studentImport.eof())
		{
			countMap++;
			stringstream ss;
			
			string line1;

			getline(studentImport, line1);

			ss << line1;

			unsigned long long int StudentID;
			string StudentName;
			string StudentAddress;
			string StudentPhoneNumber;

			if (ss >> StudentID && getline(studentImport, StudentName) && getline(studentImport, StudentAddress) && getline(studentImport, StudentPhoneNumber))
			{
				tempMap[StudentID] = new Student(StudentID, StudentName, StudentAddress, StudentPhoneNumber);
			}
			else
			{
				studentImport.close();
				//return false;
			}
		}
		studentImport.close();	
	}
	else
	{
		studentImport.close();
		for (pair<unsigned long long int, StudentInterface*> p: tempMap)
		{
		delete p.second;
		}
		tempMap.clear();
		return false;
	}
	
	ifstream studentSetImport;
	studentSetImport.open(setFileName.c_str());
	if (!studentSetImport.fail())
	{
		while(!studentSetImport.eof())
		{
			countSet++;
			stringstream ss;
		
			string line1;

			getline(studentSetImport, line1);

			ss << line1;
		
			unsigned long long int StudentID;
			string StudentName;
			string StudentAddress;
			string StudentPhoneNumber;


			if (ss >> StudentID && getline(studentSetImport, StudentName) && getline(studentSetImport, StudentAddress) && getline(studentSetImport, StudentPhoneNumber))
			{
				tempSet.insert(new Student(StudentID, StudentName, StudentAddress, StudentPhoneNumber));
			}
			else
			{
				studentSetImport.close();
				//return false;
			}
		}
		studentSetImport.close();	
	}
	else
	{
		studentSetImport.close();
		for (StudentInterface* s : tempSet)
		{
			delete s;
		}
		tempSet.clear();
		return false;
	}

	if (tempMap.size() == countMap && tempSet.size() == countSet)
	{
		for (pair<unsigned long long int, StudentInterface*> p: tempMap)
		{
			meMap[p.first] = p.second;
		}

		for (StudentInterface* s : tempSet)
		{
			meSet.insert(s);
		}

		studentSetImport.close();
		studentImport.close();
		return true;

	}
	
	studentSetImport.close();
	studentImport.close();

	for (StudentInterface* s : tempSet)
	{
		delete s;
	}

	for (pair<unsigned long long int, StudentInterface*> p: tempMap)
	{
	delete p.second;
	}

	tempMap.clear();
	tempSet.clear();
	return false;
}

bool GPA::importGrades(string fileName)
{
	/*
	* importGrades()
	*
	* Read in and parse through the given file. Each part of an entry in the file
	* is given on a separate line in the file. Student ID is first, course is
	* second, and grade is last. There are no blank lines between entries. The
	* following is an example file:
	*
	* 	5291738860
	* 	CHEM134
	* 	A
	* 	9251734870
	* 	BOT180
	* 	B
	* 	9251733870
	* 	PE273
	* 	D+
	* 	5291738760
	* 	HIS431
	*  	A-
	*
	* Compute the GPA by finding the average of all the grades with a matching student ID
	* in the Grade file. The GPA is calculated by taking a Student's total sum GPA and 
	* dividing by the number of classes taken. If the given student ID has no matching 
	* grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
	* names so long as the total number of courses taken is counted.
	*
	* You may assume that the given student ID exists in the map or set.
	*
	* Use the following point values for each grade.
	*
	*		  A = 4.0  A- = 3.7
	*	B+ = 3.4  B = 3.0  B- = 2.7
	*	C+ = 2.4  C = 2.0  C- = 1.7
	*	D+ = 1.4  D = 1.0  D- = 0.7
	*		  E = 0.0
	*
	* Returns false if an invalid filename is given, otherwise true.
	*/
	map<string,double> GRADE;
	GRADE["A"] = 4.0;
	GRADE["A-"] = 3.7;
	GRADE["B+"] = 3.4;
	GRADE["B"] = 3.0;
	GRADE["B-"] = 2.7;
	GRADE["C+"] = 2.4;
	GRADE["C"] = 2.0;
	GRADE["C-"] = 1.7;
	GRADE["D+"] = 1.4;
	GRADE["D"] = 1.0;
	GRADE["D-"] = 0.7;
	GRADE["E"] = 0.0;

	ifstream GradeImport;
	GradeImport.open(fileName.c_str());
	if (!GradeImport.fail())
	{
		while (!GradeImport.eof())
		{
			stringstream ss;


			string line1;

			getline(GradeImport, line1);

			ss << line1;
		
			unsigned long long int StudentID;
			string CourseName;
			string courseGrade;

			if (ss >> StudentID && getline(GradeImport, CourseName) && getline(GradeImport, courseGrade))
			{
				
				if (meMap.count(StudentID) == 1)
				{
					double addThis = GRADE.at(courseGrade);
					meMap.at(StudentID)-> addGPA(addThis);
				}
				else ////If it is not in the Map, then it is in the set.
				{
					double addThis = GRADE.at(courseGrade);
					for (StudentInterface* s: meSet)
					{

						if (s->getID() == StudentID)
						{
							s->addGPA(addThis);
						}
					}
				}
			}

		}
		GradeImport.close();
	}
	else
	{
		GradeImport.close();
		return false;
	}


	GradeImport.close();
	return true;
}

string GPA::querySet(string fileName)
{
	/*
	* querySet()
	*
	* Read in and parse through the given file. The 'Query' file contains a list of
	* student ID numbers. Each entry in the Query file is a student ID given on a
	* line by itself. You are to compute and report the GPA for each of the students
	* listed in the Query file. The following is an example Query file:
	*
	* 	5291738860
	* 	9251733870
	*
	* For each student ID given in the Query file, use the student information stored in
	* your set to compute the GPA for the student and create an output string which
	* contains the student ID, GPA, and name. If the given student ID does not match any 	
	* student, do not give any output for that student ID. Each line of the output string
	* contains student ID, GPA, and name as shown:
	*
	* 	5291738860 2.85 Dick B. Smith
	*	9251733870 3.00 Harry C. Anderson
	*
	* Return a string representation of the given query. If an invalid file name is given,
	* then return an empty string. The precision of the GPA will be rounded to two decimal places.
	* There will be a trailing new line.
	*/
	stringstream toReturn;

	ifstream queryImport;
	queryImport.open(fileName.c_str());
	if (!queryImport.fail())
	{
		while (!queryImport.eof())
		{
			stringstream ss;

			string line;
			unsigned long long int input;
			getline(queryImport, line);
			ss << line;

			unsigned long long int SID;

			if (ss >> SID)
			{

				for (StudentInterface* s: meSet)
				{

					if (s->getID() == SID)
					{
						toReturn << s->getID() << " " << s->getGPA() << " " << s->getName() << endl;
					}
				}
				
			}
		}
	}

	
	queryImport.close();
	return toReturn.str();

}

string GPA::queryMap(string fileName)
{

	/*
	* queryMap()
	*
	* Read in and parse through the given file. The 'Query' file contains a list of
	* student ID numbers. Each entry in the Query file is a student ID given on a
	* line by itself. You are to compute and report the GPA for each of the students
	* listed in the Query file. The following is an example Query file:
	*
	* 	5291738860
	* 	9251733870
	*
	* For each student ID given in the Query file, use the student information stored in
	* your map to compute the GPA for the student and create an output string which
	* contains the student ID, GPA, and name. If the given student ID does not match any 			 
	* student, do not give any output for that student ID. Each line of the output string
	* contains student ID, GPA, and name as shown:
	*
	* 	5291738860 2.85 Dick B. Smith
	*	9251733870 3.00 Harry C. Anderson
	*
	* Return a string representation of the given query. if an ivalid file name is given,
	* then return an empty string. The precision of the GPA will be rounded to two decimal places.
	* There will be a trailing new line.
	*/
	stringstream toReturn;

	ifstream queryImport;
	queryImport.open(fileName.c_str());
	if (!queryImport.fail())
	{
		while (!queryImport.eof())
		{
			stringstream ss;

			string line;
			unsigned long long int input;
			getline(queryImport, line);
			ss << line;

			unsigned long long int SID;

			if (ss >> SID)
			{

				for (pair<unsigned long long int, StudentInterface*> p: meMap)
				{

					if (p.first == SID)
					{
						toReturn << p.second->getID() << " " << p.second->getGPA() << " " << p.second->getName() << endl;
					}
				}
				
			}
		}
	}

	
	queryImport.close();
	return toReturn.str();
}

void GPA::clear()
{

	for (StudentInterface* s : meSet)
	{
		delete s;
	}

	for (pair<unsigned long long int, StudentInterface*> p: meMap)
	{
		delete p.second;
	}

	meMap.clear();
	meSet.clear();
}