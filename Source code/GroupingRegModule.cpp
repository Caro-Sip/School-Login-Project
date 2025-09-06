#include <iostream>
#include <string>
#define NOMINMAX
#include <windows.h>
#include <limits>
#include "UserProfile.h"

using namespace std;

void login::GroupingRegModule() {
	int choice;
	cout << "Welcome to Group Registration Module " << name << "!\n";
	cout << "Choose ONE of the following groupings:\n";
	cout << " 1 - 1E1\n";
	cout << " 2 - 1E2\n";
	cout << " 3 - 1E3\n";
	cout << " 4 - 1E4\n";
	cout << " 0 - Exit to Main Page\n";
	while (true)
	{
		cout << "Group selection: ";
		cin >> choice;
		cout << endl;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice. Please select a valid grouping.\n";
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (choice >= 1 && choice <= 4) {
			switch (choice) {
			case 1:
				groupingtemp[grp] = "1E1";
				break;
			case 2:
				groupingtemp[grp] = "1E2";
				break;
			case 3:
				groupingtemp[grp] = "1E3";
				break;
			case 4:
				groupingtemp[grp] = "1E4";
				break;
			}

			grprow = choice - 1;
			cout << "You have chosen grouping " << groupingtemp[grp] << "\n";
			cout << "Loading Group Unit Module";
			waiting(100);
			system("cls");
			GroupUnitModule();
		}
		else if (choice == 0) {
			cout << "Returning to Main Page";
			waiting(100);
			system("cls");
			Main_menu();
		}
	}
}