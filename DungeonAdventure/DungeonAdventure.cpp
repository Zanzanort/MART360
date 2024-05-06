#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

class Hero {
public:
	int health = 10;
	int gold = 0;
};

int rollDie(int sides = 6) {
	return rand() % sides + 1;
}

string askYesNo(string question) {
	string response;

	cout << question.append(" [Yes/No] ? ");
	cin >> response;
	cout << "\n";
	return response;
}

int main(){
	srand((unsigned int)time(0));

	bool isAlive = true;
	string response;
	bool exit = false;
	int pRoll = 0;
	int eRoll = 0;
	int lastGrab = 0;
	int turnCount = 0;
	Hero you;

	cout << "You have come to this orc-infested dungeon seeking riches.\nWith nothing to your name but the clothes on your back,\nyou now stand in front of the dungeon's entrance.\n";
	do {
		response = askYesNo("Do you want to continue");
		if (response == "yes" || response == "Yes" || response == "Y" || response == "y") {
			turnCount++;
			cout << "It doesn't take long before you come across an Orc guarding a mound of gold.\nAs it raises its weapon to attack, you scramble to raise your shield.\n";
			pRoll = rollDie();
			eRoll = rollDie();
			if (pRoll >= eRoll) {
				you.health--;
				lastGrab = rand() % 15 + 1;
				if (you.health > 0) {
					cout << "You mostly block the attack and grab ";
					cout << lastGrab;
					cout << " golden coins from the pile.\nYou make your escape, knowing there are only so many times that will work.\n";
					you.gold = you.gold + lastGrab;
				}
				else {
					cout << "You block the attack but you fall over from exhaustion, and the Orc wastes no time in bringing your life to an end.\n";
					isAlive = false;
					exit = true;
				}
			}
			if (pRoll < eRoll) {
				you.health = you.health - (eRoll - pRoll);
				if (you.health > 0) {
					cout << "The Orc's weapon slices into you, leaving you badly wounded.\nYou make your escape none the richer.\n";
				}
				else {
					cout << "The Orc's weapon slices into you, and you die.\n";
					isAlive = false;
					exit = true;
				}
			}
		}
		else if (response == "no" || response == "No" || response == "N" || response == "n") {
			cout << "You decide to take your leave of this awful place, and leave while you still draw breath.\n";
			exit = true;
		}
		else {
			cout << "One who stumbles on such a simple question shouldn't brave the dungeon any farther.\n";
			exit = true;
		}
	} while (exit == false);
	
	if (isAlive == true) {
		cout << "After " << turnCount << " minute(s), ";
		cout << "you leave the dungeon ";
		cout << you.gold;
		cout << " coins richer.\n";
		if (you.gold > 20 && you.health < 5) {
			cout << "You really ought to see a doctor though.\n";
		}
		else if (you.health < 5) {
			cout << "Unfortunately, you can't afford to have your injuries treated.\n";
		}
		else if (you.health == 10) {
			cout << "That said, you didn't even enter the dungeon, so what can you expect?\n";
		}
	}
	else {
		cout << "Only " << turnCount << " minute(s) into your expedition,\n";
		cout << "your body lay on the ground, ";
		if (you.gold == 0) {
			cout << "as penniless as when you arrived.\n";
		}
		else {
			cout << "surrounded by the " << you.gold << " coins you gave your life for.\n";
		}
	}
	cout << "\nThanks for Playing!";
	return 0;
}