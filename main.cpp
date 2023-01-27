#include <iostream>
#include <fstream>
#include <limits>

using namespace std;
class Player{ // Controls the actions, logic, and stats of the player in the game
public:
};
class Enemy{ // This MAY become Event
public:
};
class Event : public Enemy{ // This has an inheritance of Enemy because event could be enemy based.
public:
};
class Item { // For Items and their item ids
public:
};
class Save { // save system vv
public:
string cmd;
string brand = "base";
string mods;
bool modded() {
	string tmp;
	ifstream isave (".saved_game");
	isave.seekg(-1,ios::end);
	while (getline (isave,tmp)) {
		cout << tmp << endl;
	}
	return true;
}
string exist() {
	cout << "Continue Game?\nPossible commands are :\n start,play,continue,new,backup,quit,exit\n";
	cout << "> ";
	cin >> cmd;
	return cmd;
	}
bool mksave() {
	ofstream osave (".saved_game");
	if (osave.is_open()) {
		cout << "It appears that there isn't a save where this is being executed. Making a new save." << endl;
		osave << "[gamebeg]\n";
		osave << "\nmodsrequire:";
		osave << brand << endl;
		osave << "\n[gameend]";
		osave.close();
		return true;
	}else{
		cout << "You do not have permission to save here!" << endl;
		return 1;
	}
}
int chksave() { // Checks for save
	ifstream isave (".saved_game");
	if(isave.is_open()){return 0;}else{return 1;}
}
std::ifstream& RLine(std::ifstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
};
int playgame(int startstate) {
	if (startstate == 0) {
		ifstream isave(".saved_game");
		ofstream osave(".saved_game");
		
		return 0;
	} else if (startstate == 1) {
		cout << "Already saved.\n";
		return 0;
	}
	return 0;
}

int main() {
	Player player;
	Save save;
	if (save.chksave() == 0) { // Checks if the game found and opened the save
		save.modded();
		save.exist();
		if (save.cmd == "play" || save.cmd == "start" || save.cmd == "continue")
		{playgame(1);}
	} else if (save.mksave() == true){
		playgame(0);
	} else {
		return 1;
	}
	return 0;
}