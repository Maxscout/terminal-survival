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

int main() {
	string test, cmd, brand;
	brand = "base";
	ifstream isave (".saved_game");
	ofstream osave (".saved_game");
	Player player;
	if (isave.is_open()) { // Checks if the game found and opened the save
		cout << "Continue Game?\nPossible commands are :\n start,play,continue,new,backup,quit,exit\n";
		cout << "> ";
		cin >> cmd;
	} else { // Creates save if it isn't in the running directory
	cout << "It appears that there isn't a save where this is being executed. Making a new save." << endl;
	osave << "[gamebeginningv1]\n";
	osave << "area:newworld\nstate:begin\nstoryline:base\nmodsrequire:base\n";
	osave << "\n[gameend]";
	cmd = "gameconditioned";
	} if (cmd == "gameconditioned") {	
		playgame(0);
	} else if (cmd == "play" || cmd == "start" || cmd == "continue") {
		playgame(1);
	} else {
		cout << "Invalid cmd!" << endl;
	}
	osave.close();
	isave.close();
	return 0;
}

int playgame(int startstate) {
	if (startstate == 0) {
		osave.seekp(0,ios::beg);
		isave.seekg(0,ios::beg);
	}
}