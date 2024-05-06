#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

#include "FavGamesLoadSave.h"

using namespace std;



int main() {

	vector<string> favGames;
    favGames = loadGames();
	while (true) {  
		cout << "What will you do?\n 1: Add game\n 2: Read list\n 3: Quit\n 4: Clear List\n 5: Edit List\n Select:   ";
		string input;
		getline(cin, input);
		cout << "\n";

		if (input == "1") {
			cout << "Add which game? \n";
			getline(cin, input);
			favGames.push_back(input);
			cout << "\n";
		}
		else if (input == "2") {
			for (int i = 0; i < favGames.size(); i++) {
				cout << favGames[i] << "\n";
			}
			cout << "\n";
		}
		else if (input == "3") {
			cout << "saving...\n";
			saveGames(favGames);
			cout << "done!\n\n";
			break;
		}
		else if (input == "4") {
			favGames.clear();
		}
		else if (input == "5") {
			if (favGames.size() > 0) {
				cout << "Select which game to edit: \n";
				for (int i = 0; i < favGames.size(); i++) {
					cout << i << ": " << favGames[i] << "\n";
				}
				cout << "\n\nGame number? ";
				int which;
				cin >> which;
				getline(cin, input);
				if (which < 0 || which > favGames.size()) {
					cout << "Invalid number\n";
				}
				else {
					favGames.erase(next(favGames.begin(), which));
					cout << "Update to? \n";
					string updatedName;
					getline(cin, updatedName);
					favGames.insert(next(favGames.begin(), which), updatedName);
					cout << "\n";
				}
			}
			else {
				cout << "No games to edit.\n";
			}
		}
		else {
			cout << "Invalid input, use 1, 2, 3, 4, or 5.\n";
		}
	}
}