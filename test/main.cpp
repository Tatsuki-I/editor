#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

int main() {
	std::string filename;
	std::string swapname;

	std::cout << "Enter filename." << std::endl;
	std::cin >> filename;

	swapname = filename + ".swap";

	std::ofstream writeFile;
	std::ofstream writeSwap;
	std::ifstream readSwap(swapname, std::ios::in);
	writeFile.open(filename.c_str(), std::ios::out);
	writeSwap.open(swapname.c_str(), std::ios::out);

	std::cout << "Please write." << std::endl;

	std::string writeLineBuffer;

	for(int i = 0; i < 10; i++) {
		std::cin >> writeLineBuffer;
		writingSwap << writeLineBuffer << std::endl;
	}
	std::string readLineBuffer;
	while(!readSwap.eof()) {
		std::getline(readSwap, readLineBuffer);
		writeFile << readLineBuffer << std::endl;
	}

	return 0;
}
