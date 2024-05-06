#include "C415Includes.h"
#include "C415Functions.h"


int main() {
	
	repeatString("test", 5);
//
	cout << "\n";
//
	robot Jim("Jim", 10);
	repeatString(Jim.getName(), Jim.getCharge());
//
	cout << "\n";
//
	ofstream myFile;
	myFile.open("TextFileTest.txt", ios::app);
	myFile << "Writing to File...\n";
	myFile.close();
//
	cout << "\n";
//
	ifstream nFile;
	nFile.open("namai.txt");
	string line;
	if (nFile.is_open()) {
		while (getline(nFile, line)) {
			cout << line << "\n";
		}
	}
	else {
		cout << "Unable to read\n";
	}
	nFile.close();
//
	return 0;
}