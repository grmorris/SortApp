#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

CONST int MAXSIZE = 100;

int main() {
	vector<int> list;
	int test;
	ifstream listInput;
	listInput.open("list.txt");
	for (i = 0; i < 100; i++){
		getline(listInput, test);
		cout << test << endl;
	}
	listInput.close();
	return 0;
}