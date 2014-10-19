#include <vector>
#include <algorithm>
using namespace std;


//Struct to be passed to the thread containing the sorted and unsorted lists
struct ARGS {
	vector<int> v; //unsorted list
	vector<int> w; //sorted list
};


//Sort the front half of the list (from the first element to the size/2 element)
DWORD WINAPI frontSort(LPVOID v){
	ARGS *temp = (ARGS*)v;
	sort(temp->v.begin(), temp->v.begin() + (temp->v.size() / 2));
	return 0;
}


//Sort the back half of the list (from the size/2 element to the last element)
DWORD WINAPI backSort(LPVOID v){
	ARGS *temp = (ARGS*)v;
	sort(temp->v.begin() + ((temp->v.size() / 2)), temp->v.begin() + temp->v.size());
	return 0;
}


//Merge the two halves of the list together
DWORD WINAPI mergeSort(LPVOID v){
	ARGS *temp = (ARGS*)v;
	temp->w.resize(temp->v.size());
	merge(temp->v.begin(), temp->v.begin() + (temp->v.size() / 2), temp->v.begin() + ((temp->v.size() / 2)), temp->v.begin() + temp->v.size(), temp->w.begin());
	return 0;
}