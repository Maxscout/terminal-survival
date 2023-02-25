#include "terminal survival.h"



int playgame(int startstate) {
	if (startstate == 1) {
		cout << "Already saved.\n";
		return 0;
	}
	iids item = stick;
	ifstream isave(".saved_game");
	ofstream osave(".saved_game");
	Biome biomes;
	cout << "The chaos is making your head hurt. But you somehow know it will go away.\n";
	srand(time(NULL));
	int seed = rand() % 9999999 + 1;
	srand(seed);
	osave << "initseed_" << seed << endl;
	int biome = rand() % 5 + 1;
	string* itemid[3];
	osave << "0\n_" << biome << "\n_" << seed << endl;
	osave << "_";
	if (biome == 1) {
		cout << "You awaken as if you were there all along not remembering anything. You see many trees around.\n";
		osave << biomes.forestitems[1] << "\n_" << biomes.forestitems[3];
		cout << "You found " << biomes.forestitems[2] << " and " << biomes.forestitems[4];
	}
	else if (biome == 2) {
		cout << "You're up, very suddenly, standing with sand surrounding every bit of your vision with few cactuses.\n";
		osave << biomes.desertitems[1];
		cout << "You found " << biomes.desertitems[2];
	}
	else if (biome == 3) {
		cout << "Brrr! It's very cold and theres trees around.\n";
		osave << biomes.snowforestitems[1] << "\n_" << biomes.snowforestitems[3] << "\n_" << biomes.snowforestitems[5];
		cout << "You found " << biomes.snowforestitems[2] << ", " << biomes.snowforestitems[4] << ", and " << biomes.snowforestitems[6];
	}
	else if (biome == 4) {
		cout << "Yuck! You're knee-deep in mud with some trees that surround you.\n";
		osave << biomes.swampitems[1] << "\n_" << biomes.swampitems[3] << "\n_" << biomes.swampitems[5];
		cout << "You found " << biomes.swampitems[2] << ", " << biomes.swampitems[4] << ", and " << biomes.swampitems[6];
	}
	else if (biome == 5) {
		cout << "You're very high in the sky on some mountains. It isn't as cold as you thought.\n";
		osave << biomes.mountainsitems[1];
		cout << "You found " << biomes.mountainsitems[2];
	}
	cout << ".\nPress enter to close.\n";
	cin.ignore();
	osave.close();
	return 0;
}

class Biome {
public:
	string forestitems[4] = { ,stick[3],tree[1],tree[3] };
	string desertitems[2] = { cactus[1],cactus[3] };
	string snowforestitems[6] = { snow[1],snow[3],stick[1],stick[3],tree[1],tree[3] };
	string swampitems[6] = { sludge[1],sludge[3],tree[1],tree[3],stick[1],stick[3] };
	string mountainsitems[2] = { stone[1],stone[3] };
};