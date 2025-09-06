#include <iostream>
#include <string>
#include <limits>
#define NOMINMAX
#include <windows.h>
#include <fstream>
#include "UserProfile.h"

using namespace std;

void login::GroupUnitModule() {
	int choice;
	cout << "Please select the following units for group " << groupingtemp[grp] << "\n\n";
	cout << " 1 - Programming (" << AvailableUnit[grprow][0] << " slots available)\n";
	cout << " 2 - Physics 1 (" << AvailableUnit[grprow][1] << " slots available)\n";
	cout << " 3 - Mathematics 2 (" << AvailableUnit[grprow][2] << " slots available)\n";
	cout << " 4 - Writing and Research Skills (" << AvailableUnit[grprow][3] << " slots available)\n";
	cout << " 5 - Select ALL the units(only if you have not chosen individual unit)\n";
	cout << " 0 - Exit to Main Page\n";
	while (true) {
		cout << "Choice: ";
		cin >> choice;
		
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Sorry, please select option 0 to 5 only!\n";
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice) {
		case 1:
		case 2:
		case 3:
		case 4:
			if (RegisteredUnits[choice - 1]) {
				cout << "Sorry, you have previously registered into this unit!\n\n";
			}
			else if (AvailableUnit[grprow][choice - 1] <= 0) {
				cout << "Sorry, no available slot for group " << groupingtemp[grp] << " for " << subjects[choice - 1] << "!\n\n";
				break;
			}
			else {
				RegisteredUnits[choice - 1] = true;
				AvailableUnit[grprow][choice - 1]--;
				cout << "You have successfully registered into " << groupingtemp[grp] << " for ";
				switch (choice) {
				case 1:
					unit[choice - 1] = subjects[choice - 1];
					grouping[choice - 1] = groupingtemp[grp];
					cout << "Programming!";
					break;
				case 2:
					unit[choice - 1] = subjects[choice - 1];
					grouping[choice - 1] = groupingtemp[grp];
					cout << "Physics 1!";
					break;
				case 3:
					unit[choice - 1] = subjects[choice - 1];
					grouping[choice - 1] = groupingtemp[grp];
					cout << "Mathematics 2!";
					break;
				case 4:
					unit[choice - 1] = subjects[choice - 1];
					grouping[choice - 1] = groupingtemp[grp];
					cout << "Writing and Research Skills!";
					break;
				}
				cout << endl;
				registered = true;
				AvailableUnitOutput();
				grp++;

				cout << "\nLoading grouping registration module";
				waiting(100);
				system("cls");
				Main_menu();
			}
			break;
		case 5:
			if (RegisteredUnits[0] || RegisteredUnits[1] || RegisteredUnits[2] || RegisteredUnits[3]) {
				cout << "Sorry, you have previously registered into " << groupingtemp[grp] << "for individual unit(s)!\n";
			}
			else if (AvailableUnit[grprow][0] <= 0 || AvailableUnit[grprow][1] <= 0 || AvailableUnit[grprow][2] <= 0 || AvailableUnit[grprow][3] <= 0) {
				cout << "Sorry, one of the units in the group " << groupingtemp[grp] << " is not available!\n\n";
				break;
			}
			else {
				for (int i = 0; i < 4; i++) {
					unit[i] = subjects[i];
				}

				for (int i = 0; i < 4; i++) {  
					AvailableUnit[grprow][i]--;  
					grouping[i] = groupingtemp[grp];  
					RegisteredUnits[i] = true;  
				}

				cout << "You have successfully registered for all units!\n";
			}
			AvailableUnitOutput();
			registered = true;
			cout << "\nLoading grouping registration module";
			waiting(100);
			system("cls");
			Main_menu();
			
			break;
		case 0:
			cout << "Returning to Main Page";
			waiting(100);
			system("cls");
			Main_menu();
			break;
		default:
			cout << "Sorry, please select option 0 to 5 only!\n\n";
		}
	}
}