#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int x3(int x) {
	x = x * 3;
	return x;
}
int square(int x) {
	x = x * x;
	return x;
}
int power(int x, int y) {
	int z = x;
	for (int i = 1; i < y; i++) {
		x = x * z;
	}
	return x;
}

void displayVec(vector<string> x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i];
	}
}
string readVec(vector<string> x) {
	string read = "";
	for (int i = 0; i < x.size(); i++) {
		read.append(x[i]);
	}
	return read;
}

vector<string> addToVec(vector<string> x, string y) {
	x.push_back(y);
	return x;
}
void addToRVec(vector<string>& x, string y) {
	x.push_back(y);
}

void combineVec(vector<string>& x, vector<string> y) {
	for (int i = 0; i < y.size(); i++) {
		x.push_back(y[i]);
	}
}

int globalInt = 0;

class testClass {
public:

};


int main(){

	int test = 50;
	cout << test << " times 3 is " << x3(test) << ".\n";

	cout << power(5, 3) << "\n";
	cout << power(2, 20) << "\n";

	cout << "\n";
	
	vector<string> testVi ={"a","b","c","d"};
	vector<string> testVii = { "g","h","j","k"};
	
	displayVec(testVi);
	cout << readVec(testVi);
	cout << "\n";

	addToVec(testVi, "e");
	addToRVec(testVi, "e");
	addToRVec(testVi, "f");
	displayVec(testVi);
	cout << "\n";

	combineVec(testVi, testVii);
	cout << readVec(testVi);
	cout << "\n\n";

	map<string, string> dict;
	dict["mario"] = "it'sa me!";
	cout << dict["mario"] << "\n";

}