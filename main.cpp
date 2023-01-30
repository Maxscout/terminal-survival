#include <iostream>
#include <fstream>
#include <limits>

using namespace std;
class Player{ // Controls the actions, logic, and stats of the player in the game
public:
};
class Biome{
	public:
		int forest[3];
		int desert[3];
		int snowforest[3];
		int swamp[3];
		int mountains[3];
};
class Enemy{ // This MAY become Event
public:
};
class Event : public Enemy{ // This has an inheritance of Enemy because event could be enemy based.
public:
};
class Item { // For Items and their item ids
public:
	int stick[2] = {1,1};
	int stone[2] = {2,2};
	int tree[2] = {3,1};
	int dirt[2] = {4,6};
	int sludge[2] = {8,6};
	int plant[2] = {5,4};
	int cactus[2] = {6,4};
	int sand[2] = {7,5};
};
class Save { // save system vv
public:
string cmd;
string mods;
bool modded() {
	string tmp;
	ifstream isave (".saved_game");
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
		Item items;
		cout << "The chaos is making your head hurt. But you somehow know it will go away.\n";
		srand(time(NULL));
		int seed = rand() % 9999999 + 1;
		srand(seed);
		osave << "initseed_" << seed << endl;
		int biome = rand() % 5 + 1;
		int* blockitem[2];
		osave << "0\n_" << biome << "\n_" << seed << endl;
		if (biome == 1) {
			cout << "You awaken as if you were there all along not remembering anything. You see many trees around.\n";
			blockitem[1] = &items.tree[1];
			blockitem[2] = &items.stick[1];
		} if (biome == 2) {
			cout << "You're up, very suddenly, standing with sand surrounding every bit of your vision and few cactuses.\n";
			blockitem[1] = &items.cactus[1];
		} if (biome == 3) {
			cout << "Brrr! It's very cold and theres trees around.\n";
			blockitem[1] = &items.tree[1];
		} if (biome == 4) {
			cout << "Yuck! You're knee-deep in mud with some trees that surround you.\n";
			blockitem[1] = &items.tree[1];
			blockitem[2] = &items.sludge[1];
		} if (biome == 5) {
			cout << "You're very high in the sky on some mountains. It isn't as cold as you thought.\n";
			blockitem[1] = &items.stone[1];
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
