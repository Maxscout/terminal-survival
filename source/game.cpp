#include "terminal survival.h"



int playgame(int startstate) {
	if (startstate == 1) {
		cout << "Already saved.\n";
		return 0;
	}
	iids stick;
	stick = stone;
	ifstream isave(".saved_game");
	ofstream osave(".saved_game");
	cout << "The chaos is making your head hurt. But you somehow know it will go away.\n";
	srand(time(NULL));
	int seed = rand() % 9999999 + 1;
	srand(seed);
	osave << "initseed_" << seed << endl;
	int biome = rand() % 5 + 1;
	string* itemid[3];
	osave << "0\n_" << biome << "\n_" << seed << endl;
	osave << "_";
	switch(biome){
		case 1: //Forest
		cout << stick;
		break;
		case 2: //Desert
		cout << stick;
		break;
		case 3: //Snowy place with trees
		cout << stick;
		break;
		case 4: //Swamp
		cout << stick;
		break;
		case 5: //Mountains
		cout << stick;
		break;
	}
	cout << ".\nPress enter to close.\n";
	cin.ignore();
	osave.close();
	return 0;
}
/*
class Biome {
public:
	string forestitems[4] = { ,stick[3],tree[1],tree[3] };
	string desertitems[2] = { cactus[1],cactus[3] };
	string snowforestitems[6] = { snow[1],snow[3],stick[1],stick[3],tree[1],tree[3] };
	string swampitems[6] = { sludge[1],sludge[3],tree[1],tree[3],stick[1],stick[3] };
	string mountainsitems[2] = { stone[1],stone[3] };
};
*/