#include <iostream>
#include <fstream>
#include <string>
#include "UserProfile.h"

using namespace std;


void login::PrintStudentData() {
	ofstream file("StudentData.txt", ios::app);
	if (file.is_open()) {
		file << name << endl;
		file << id << endl;
		file << semester << endl;
		file << year << endl;
		for (int i = 0; i < 4; i++) {
			if (RegisteredUnits[i]) {
				file << unit[i] << endl;
				file << grouping[i] << endl;
			}
		}
		file << "End" << endl;
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}
// this function only append** new data without checking for duplicates
// so we need to use ReadStudentData() to check for duplicates
// using previousRegister and newRegistry to trigger the function
// so Read function is not triggered everytime user login

void login::ReadStudentData() {
	ifstream file("StudentData.txt");
	bool found = false;

	if (file.is_open()) {
		while (!file.eof()) {
			string tempname, tempid, tempsemester, tempyear;
			string tempunit[4] = {}, tempgrouping[4] = {};
			int unitCount = 0;

			getline(file, tempname);
			if (tempname.empty()) break;

			getline(file, tempid);
			getline(file, tempsemester);
			getline(file, tempyear);

			string line;
			while (getline(file, line) && line != "End" && unitCount < 4) {
				tempunit[unitCount] = line;
				if (getline(file, line)) {
					tempgrouping[unitCount] = line;
					unitCount++;
				}
			}

			if (tempname == name && tempid == id) {
				found = true;
				name = tempname;
				id = tempid;
				semester = tempsemester;
				year = tempyear;
				for (int i = 0; i < unitCount; i++) {
					unit[i] = tempunit[i];
					grouping[i] = tempgrouping[i];
					RegisteredUnits[i] = true;
				}
				registered = true;
				previousRegister = true;
				cout << "Welcome back, " << name << "!\n";
				Main_menu();
				break;
			}
		}
		file.close();

		if (!found) {
			cout << "No previous data found for this user.\n";
		}
	}
	else {
		cout << "Unable to open Student Data file, proceeding with new login\n";
	}
}
