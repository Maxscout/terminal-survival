#include "terminal survival.h"

int main() {
	Save save;
	if (save.chksave() == 0) { // Checks if the game found and opened the save
		save.exist();
		if (save.cmd == "play" || save.cmd == "start" || save.cmd == "continue")
		{
			playgame(1);
		}
	}
	else if (save.mksave() == true) {
		playgame(0);
	}
	else {
		return 1;
	}
	return 0;
}