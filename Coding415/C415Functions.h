//#pragma once

#include "c415includes.h"

// Repeat string by number of times
void repeatString(string sInput, int iInput) {
	for (int i = 0; i < iInput; i++) {
		cout << sInput;
	}
}

class robot {
private:
	string name;
	int charge;
public:
	void status() {
		cout << "Robot Name: " << name << ".\n";
		cout << "Robot Battery: " << charge << ".\n";
	}
	robot(string rName = "Rob", int rCharge = 75) {
		cout << "Constructing new robot...\n";
		name = rName;
		charge = rCharge;
	}

	void setName(string rName) {
		name = rName;
	}
	void setCharge(int rCharge) {
		charge = rCharge;
	}
	string getName() {
		return name;
	}
	int getCharge() {
		return charge;
	}
};