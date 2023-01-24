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

int playgame(int startstate) {
	if (startstate == 0) {
		return 0;
	} else if (startstate == 1) {
		cout << "Already saved.\n";
		return 0;
	}
	return 0;
}
class Save { // save system vv
public:
string cmd;
string brand = "base";
string exist() {
	cout << "Continue Game?\nPossible commands are :\n start,play,continue,new,backup,quit,exit\n";
	cout << "> ";
	cin >> cmd;
	return cmd;
	}
int mksave() {
	ofstream osave (".saved_game");
	if (osave.is_open()) {
		cout << "It appears that there isn't a save where this is being executed. Making a new save." << endl;
		osave << "[gamebeginningv1]\n";
		osave << "area:newworld\nstate:begin\nmodsrequire:";
		osave << brand << endl;
		osave << "\n[gameend]";
		osave.close();
		return 0;
	}else{
		cout << "You do not have permission to save here!" << endl;
		return 1;
	}
}
int chksave() { // Checks for save
	ifstream isave (".saved_game");
	if(isave.is_open()){return 0;}else{return 1;}
}
};

int main() {
	Player player;
	Save save;
	string opt;
	if (save.chksave() == 0) { // Checks if the game found and opened the save
		save.exist();
		if (save.cmd == "play" || save.cmd == "start" || save.cmd == "continue")
		{playgame(1);}
	} else if (save.mksave() == 0){
		playgame(0);
	} else {
		return 1;
	}
	return 0;
}