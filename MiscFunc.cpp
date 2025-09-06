#include <iostream>
#include <windows.h>
#include <string>
#include <string.h>
#include <fstream>
#include <limits>
#include <iomanip>
#include "UserProfile.h"



using namespace std;

void waiting(int t) {
	for (int i = 0; i < 5; i++) {
		cout << "\\";
		Sleep(t);
		cout << "\b|";
		Sleep(t);
		cout << "\b/";
		Sleep(t);
		cout << "\b-";
		Sleep(t);
	}
}


string trimmer(string& input) {
	string result;
	bool inWord = false;
	int start = 0, end = input.length();

	while (start < static_cast<int>(input.length()) && input[start] == ' ') {
		start++;
	}

	while (end > start && input[end - 1] == ' ') {
		end--;
	}

	for (int i = start; i < end; i++) {
		char check = input[i];
		if (check != ' ') {
			result += check;
			inWord = true;
		}
		else if (inWord) {
			result += ' ';
			inWord = false;
		}
	}
	return result;
}

bool isid9(string& input) {
	return strlen(input.c_str()) == 9;
}

bool isnum(string& input) {
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

bool isid7k(string& input) {
	return input.substr(0, 4) == "7000";
}

void printfile(string filename) {
	string line;
	ifstream file(filename.c_str());
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
}
