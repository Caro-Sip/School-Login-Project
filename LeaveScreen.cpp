#include <iostream>
#include <fstream>
#include <limits>
#define NOMINMAX
#include <windows.h>
#include <string>
#include <iomanip>
#include "UserProfile.h"

using namespace std;

void login::LeaveScreen() {
	cout << "You are attempting to Exit the program.\n";
	while (true) {
		cout << "Are you sure you want to exit the program, " << name << " (ID: " << id << ") Y/N";
		cout << endl;
		cout << "Your answer: ";
		char answer;
		string input;
		getline(cin, input);
		if (input.length() == 1) {
			answer = toupper(input[0]);
			switch (answer) {
			case 'Y':
				printfile("logo.txt");
				cout << "Group 8B:\n";
				cout << "1. Suon Caro(p20240023)\n";
				cout << "2. Pav Ratana(p20240047)\n";
				cout << "3. Pong Mengheang(p20240041)\n";
				cout << "4. Sao Dalyinaco(p20240003)\n";
				cout << "Team Member Task / Job Description\n";
				cout << "=========================================================================\n";
				cout << left << setw(20) << "Suon Caro" << "Design flowchart 1 and 4 and integrate all the modules\n";
				cout << left << setw(20) << "Pong Mengheang" << "Design flowchart 3 and Develop Grouping Selection Module\n";
				cout << left << setw(20) << "Pav Ratana" << "Design flowchart 2 and semester code\n";
				cout << left << setw(20) << "Sao Dalyinaco" << "Design flowchart 5 and debugger\n";
				system("GroupPhoto.jpg");
				cout << "Thank you for using our program.\n";
				system("pause");
				exit(0);
				break;
			case 'N':
				cout << "Returning to Main Page";
				waiting(125);
				cout << "\n";
				system("cls");
				Main_menu();
				break;
			default:
				cout << "Sorry, please enter Y or N only!\n";
			}
		}
		else {
			cout << "Invalid input. Please enter singular character\n";
		}
	}
}