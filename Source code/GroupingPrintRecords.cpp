#include <iostream>
#include <fstream>
#define NOMINMAX
#include <windows.h>
#include <string>
#include <iomanip>
#include "UserProfile.h"

using namespace std;

void login::GroupingPrintRecord() {
	ofstream record("Record.txt");
	cout << "Welcome to Grouping Record Module, " << name << "!\n\n";
	cout << "Here are your registerd groupings\n\n";
	cout << "Trimester: " << semester << "F-" << year << "\n";
	cout << "Student Name: " << name << endl;
	cout << "Student ID: " << id << "\n";
	cout << left << setw(30) << "Unit" << "Grouping\n";
	cout << "======================================\n";
	for (int i = 0; i < 4; i++) {
		if (RegisteredUnits[i]) {
			cout << left << setw(30) << unit[i] << grouping[i] << endl;
		}
	}
	cout << "======================================\n\n";
	if (!previousRegister) {
		PrintStudentData();
	}
	/* so a solution is another check where if the previous user is registered
	while checking if the user added anymore subjects that will turn the flip to true
	This new check also help prevent
	*/
	else if (previousRegister && newRegistry){
		PrintStudentData();
	}
	/* The only problem with this logic is that the old user has a duplicate userdata
	so a rework of PrintStudentData() needs to be rework
	*/
	while (true) {
		cout << "Would you like to print your grouping record (Y/N)? ";
		char answer;
		string input;
		getline(cin, input);
		if (input.length() == 1) {
			answer = toupper(input[0]);
			switch (answer) {
			case 'Y':
				cout << "Printing your grouping record...\n";
				record << "Trimester: " << semester << "F-" << year << "\n";
				record << "Student Name: " << name << endl;
				record << "Student ID: " << id << "\n";
				record << left << setw(30) << "Unit" << "Grouping\n";
				record << "======================================\n";
				for (int i = 0; i < 4; i++) {
					if (RegisteredUnits[i]) {
						record << left << setw(30) << unit[i] << grouping[i] << endl;
					}
				}
				record << "======================================";
				record.close();
				cout << endl;
				cout << "Your grouping record has been printed to Record.txt\n";
				cout << "Opening Grouping Record";
				waiting(125);
				system("Record.txt");
				cout << endl;
				system("cls");
				Main_menu();
				break;
			case 'N':
				cout << "Canceling the printing";
				waiting(125);
				system("cls");
				Main_menu();
				break;
			default:
				cout << "Sorry, please enter Y or N only!\n\n";
			}
		}
		else {
			cout << "Invalid input. Please enter singular character!\n\n";
		}
	}
}