#include <iostream>
#include <string>
#define NOMINMAX
#include <Windows.h>
#include <limits>
#include "UserProfile.h"

using namespace std;

void login::Main_menu() {
    int choice;
    cout << "Group Registration Main Page\n";
    cout << "1 - Register for grouping\n";
    cout << "2 - View/Print grouping record\n";
    cout << "0 - Exit program\n\n";
    while (true) {
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sorry, please select option 0 to 2 only!\n\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            cout << "You have chosen option " << choice << "\n\n";
            cout << "Loading Main Page";
			waiting(100);
            system("cls");
            GroupingRegModule();
            break;
        case 2:
            if (registered) {
                cout << "You have chosen option " << choice << "\n\n";
                cout << "Loading Grouping Registration Module";
				waiting(100);
                system("cls");
                GroupingPrintRecord();
				Sleep(2000);
                system("cls");
                break;
            }
            else {
                cout << "You have not registered using menu 1 above\n\n";
                break;
            }
        case 0:
            cout << "You have chosen option " << choice << "\n\n";
            cout << "Loading Main Page";
            waiting(100);
            system("cls");
			LeaveScreen();
        }
    }
}