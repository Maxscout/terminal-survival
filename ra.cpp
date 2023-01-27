#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

std::ifstream& RLine(std::ifstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

int main() {
	string line;
	ifstream exa("example.txt");
	RFLine(exa, 4);
	exa >> line;
	cout << line << endl;
}