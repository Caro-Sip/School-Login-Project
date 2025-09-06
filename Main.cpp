#include <iostream>
#include "UserProfile.h"

using namespace std;

int main() {
	string name, id;
	while (true) {
		cout << "Enter your name: ";
		getline(cin, name);
		cout << endl;
		name = trimmer(name);
		if (name.empty()) {
			cout << "ERROR: Your name value cannot be blank/empty!\n\n";
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "Enter your ID: ";
		getline(cin, id);
		cout << endl;
		id = trimmer(id);
		if (id.empty()) {
			cout << "ERROR: Your ID value cannot be blank/empty!\n\n";
		}
		else if (!isid9(id)) {
			cout << "ERROR: Your ID value must be 9-digit long!\n\n";
		}
		else if (!isnum(id)) {
			cout << "ERROR: Your ID value must be numeric value only!\n\n";
		}
		else if (!isid7k(id)) {
			cout << "ERROR: Your ID value must be in 7000XXXXX format!\n\n";
		}
		else {
			break;
		}
	}
	cout << "Welcome to our Grouping Registration App, " << name << " (ID: " << id << ")!\n\n";
	cout << "Loading Main Page";
	waiting(150);
	system("cls");
	login student(name, id);
	return 0;
}