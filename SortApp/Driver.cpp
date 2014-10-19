#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include "Sort.h"
using namespace std;

const int MAXSIZE = 10; //Change this to read more/less data from input file (up to 1000)

int main() {
	DWORD threadID[3];
	ARGS args;
	HANDLE threadArray[3];

	//Input integers from a file into the unsorted list v
	int temp;
	ifstream listInput;
	listInput.open("1to1000.txt");
	for (int i = 0; i < MAXSIZE; i++){
		listInput >> temp;
		args.v.push_back(temp);
	}
	listInput.close();

	//Create two threads, one to sort the front half of the list and the other to sort the back half of the list
	threadArray[0] = CreateThread(NULL, 0, frontSort, &args, 0, &threadID[0]);
	threadArray[1] = CreateThread(NULL, 0, backSort, &args, 0, &threadID[1]);

	//Print the list size, and wait for both threads to finish
	cout << "The list size is " << args.v.size() << " elements." << endl << endl;
	WaitForMultipleObjects(2, threadArray, true, INFINITE);
	system("pause");

	//Print the thread IDs, handles, and the half-sorted unmerged list
	cout << endl << "Front sort thread ID is " << threadID[0] << " and thread handle is " << threadArray[0] << endl;
	cout << "Back sort thread ID is " << threadID[1] << " and thread handle is " << threadArray[1] << endl;
	cout << endl << "The list, with the first half and last half sorted but not merged:" << endl;
	for (int j = 0; j < args.v.size(); j++){
		cout << args.v.at(j) << endl;
	}
	system("pause");

	//Create a thread to merge the two sorted halves of the list into a new sorted list w
	threadArray[2] = CreateThread(NULL, 0, mergeSort, &args, 0, &threadID[2]);
	WaitForSingleObject(threadArray[2], INFINITE);

	//Print the new sorted list w
	cout << endl << "Merge sort thread ID is " << threadID[2] << " and thread handle is " << threadArray[2] << endl;
	cout << endl << "The list, with both halves sorted and merged into one sorted list:" << endl;
	for (int j = 0; j < args.w.size(); j++){
		cout << args.w.at(j) << endl;
	}
	system("pause");

	return 0;
}

