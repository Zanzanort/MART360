//#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

vector<string> loadGames() {
	vector<string> games;
	ifstream saveFile;
	saveFile.open("FavGames.txt");
	string line;
	if (saveFile.is_open()) {
		while (getline(saveFile, line)) {
			games.push_back(line);
		}
	}
	saveFile.close();
	return games;
}

void saveGames(vector<string> games) {
	ofstream saveFile("FavGames.txt");
	for (int i = 0; i < games.size(); i++) {
		saveFile << games[i] << "\n";
	}
	saveFile.close();
}