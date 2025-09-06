#include <iostream>
#include <fstream>

#include <string>
#include <cstdio>
#include "UserProfile.h"

using namespace std;

void login::AvailableUnitInput() {
    ifstream infile("AvailableUnit.txt");
    if (!infile) {
        cout << "Student Units Availability not found, loading default value" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                AvailableUnit[i][j] = 15;
            }
        }
    }
    else {
        cout << "Student Units Availability found, loading value" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                infile >> AvailableUnit[i][j];
            }
        }
        infile.close();
    }
    cout << "Loading Registration";
    waiting(150);
    system("cls");
}

void login::AvailableUnitOutput() {
    ofstream outfile("temp.txt");
    if (!outfile) {
        cout << "Unable to open temp.txt for writing\n";
        return;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            outfile << AvailableUnit[i][j] << " ";
        }
        outfile << std::endl;
    }
    outfile.close();
    remove("AvailableUnit.txt");

    if (rename("temp.txt", "AvailableUnit.txt") != 0) {
        cout << "Error renaming temp.txt to AvailableUnit.txt\n";
    }
    else {
        cout << "Available units saved successfully to AvailableUnit.txt\n";
    }
}
