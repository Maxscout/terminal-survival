#pragma once

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;
int playgame(int startstate);
enum iids;
class Save { // save system vv
public:
	string cmd;
	string exist() {
		cout << "Continue Game?\nPossible commands are :\n start,play,continue,new,backup,quit,exit\n";
		cout << "> ";
		cin >> cmd;
		return cmd;
	}
	bool mksave() {
		ofstream osave(".saved_game");
		if (osave.is_open()) {
			cout << "It appears that there isn't a save where this is being executed. Making a new save." << endl;
			osave.close();
			return true;
		}
		else {
			cout << "You do not have permission to save here!" << endl;
			return 1;
		}
	}
	int chksave() { // Checks for save
		ifstream isave(".saved_game");
		if (isave.is_open()) { return 0; }
		else { return 1; }
	}
	ifstream& RLine(ifstream& file, unsigned int num) {
		file.seekg(ios::beg);
		for (int i = 0; i < num - 1; ++i) {
			file.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return file;
	}
};