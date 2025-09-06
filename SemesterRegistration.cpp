#include <iostream>
#include <string>
#include <windows.h>
#include "UserProfile.h"

using namespace std;

void login::SemesterRegistration() {
	while (true) {
		cout << "Enter Semester (e.g., 1, 2, or 3): ";
		getline(cin, semester);
		semester = trimmer(semester);
		if (semester.empty()) {
			cout << "ERROR: Your semester value cannot be blank/empty!\n\n";
			continue;
		}
		else if (isnum(semester) && semester.length() == 1 && semester >= "1" && semester <= "3") {
			break;
		}
		cout << "Invalid semester. Please enter 1, 2, or 3.\n\n";
	}
	cout << endl;
	while (true) {
		cout << "Enter year (e.g., 2025): ";
		getline(cin, year);
		year = trimmer(year);
		if (year.empty()) {
			cout << "ERROR: Your year value cannot be blank/empty!\n\n";
			continue;
		}
		else if (isnum(year) && year.length() == 4 && year >= "2025" && year <= "2100") {
			break;
		}
		cout << "Invalid Year. Please enter a year between 2025 and 2100\n\n";
	}
	cout << endl;
	cout << "Thank you for your input. You are registering for Trimester " << semester << "F-" << year << endl;
	Sleep(2000);
	system("cls");
}