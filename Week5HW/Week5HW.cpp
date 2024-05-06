#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

	vector<string> favGames;
	int index = 0;
	while (true) {
		cout << "What will you do?\n 1: Add game\n 2: Read list\n 3: Quit\n Select:   ";
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
			cout << "exiting...\ndone!\n\n";
			break;
		}
		else {
			cout << "Invalid input, use 1, 2, or 3.\n";
		}
	}
}