#include <iostream>
#include <fstream>

using namespace std;
class Player{ // Controls the actions and logic of the player in the game
public:
};
class Enemy{ // This MAY become Event
public:
};
class Event : public Enemy{ // This has an inheritance of Enemy because event could be enemy based.
public:
};

int chksave() { // Checks for save
	ifstream isave (".saved_game");
	if(isave.is_open()){return 0;}else{return 1;}
}

int mksave() {
	string cmd;
	ofstream osave (".saved_game");
	if (osave.is_open()) {
		cout << "It appears that there isn't a save where this is being executed. Making a new save." << endl;
		osave << "[gamebeginningv1]\n";
		osave << "area:newworld\nstate:begin\nstoryline:base\nmodsrequire:base\n";
		osave << "\n[gameend]";
		cmd = "gameconditioned";
		return 0;
	}else{
		cout << "You do not have permission to save here!" << endl;
		return 1;
	}
}

int playgame(int startstate) {
	if (startstate == 0) {
		return 0;
	} else if (startstate == 1) {
		cout << "Already saved.\n";
		return 0;
	}
	return 0;
}

int main() {
	string test, cmd, brand;
	brand = "base";
	ifstream isave (".saved_game");
	Player player;
	if (chksave() == 0) { // Checks if the game found and opened the save
		cout << "Continue Game?\nPossible commands are :\n start,play,continue,new,backup,quit,exit\n";
		cout << "> ";
		cin >> cmd;
	} else {
		mksave();
	} if (cmd == "gameconditioned") {	
		playgame(0);
	} else if (cmd == "play" || cmd == "start" || cmd == "continue") {
		playgame(1);
	} else {
		cout << "Invalid cmd!" << endl;
	}
	ofstream osave (".saved_game");
	osave.close();
	isave.close();
	return 0;
}
// 69 LINES!!!!!!