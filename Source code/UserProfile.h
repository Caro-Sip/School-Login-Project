#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string trimmer(string& input);
bool isid9(string& input);
bool isnum(string& input);
bool isid7k(string& input);

void printfile(string filename);

void waiting(int t);

class UserProfile {
protected:
	int AvailableUnit[4][4] = { { 0, 0, 0, 0 }, 
								{ 0, 0, 0, 0 }, 
								{ 0, 0, 0, 0 }, 
								{ 0, 0, 0, 0 } };
	int grp = 0, grprow = 0;
	string name, id, semester, year;
	string groupingtemp[4] = { "", "", "", "" };
	string grouping[4] = { "", "", "", "" };
	string subjects[4] = { "Programming",
							"Physics 1",
							"Mathematics 2",
							"Writing and Research Skills" };
	string unit[4] = { "", "", "", ""};
	bool RegisteredUnits[4] = { false, false, false, false };
	bool registered = false;
	bool previousRegister = false;
	bool newRegistry = false;
};

class login : public UserProfile {
private:
	void AvailableUnitInput();
	void AvailableUnitOutput();
	void SemesterRegistration();
	void Main_menu();
	void GroupingRegModule();
	void GroupUnitModule();
	void GroupingPrintRecord();
	void LeaveScreen();
	void PrintStudentData();
	void ReadStudentData();

public:
	login(string name, string id) {
		this->name = name;
		this->id = id;
		AvailableUnitInput();
		ReadStudentData();
		SemesterRegistration();
		Main_menu();
	}
};

#endif