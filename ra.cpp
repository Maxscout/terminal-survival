#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));
	int random = rand() % 20 + 1;
	cout << random << endl;
	srand(rand() % 80000 + 1);
	random = rand() % 2210 + 1;
	cout << random << endl;
}