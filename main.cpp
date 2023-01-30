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
	string stick[1];
	string stone[1];
	string tree[1];
	string dirt[1];
	string plant[1];
	string cactus[1];
	string sand[1];
};
class Save { // save system vv
public:
string cmd;
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
ifstream& RLine(ifstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}
};
int playgame(int startstate) {
	if (startstate == 0) {
		ifstream isave(".saved_game");
		ofstream osave(".saved_game");
		cout << "The chaos is making your head hurt. But you somehow know it will go away.\n";
		srand(time(NULL));
		int seed = rand() % 9999999 + 1;
		srand(seed);
		osave.seekp(9);
		osave << "seed_" << seed << endl;
		int spawn = rand() % 5 + 1;
		srand(time(NULL));
		int randitem = rand() % 5 + 1;
		osave << "1_" << spawn << endl;
		if (spawn == 1) {
			cout << "You awaken as if you were there all along not remembering anything. You see many trees around.";
		} if (spawn == 2) {
			cout << "You're up, very suddenly, standing with sand surrounding every bit of your vision and few cactuses.";
			randitem = 6;
		} if (spawn == 3) {
			
		} if (spawn == 4) {
			
		} if (spawn == 5) {
			
		}
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