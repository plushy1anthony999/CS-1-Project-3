#include <iostream>
#include <string>

using namespace std;

/* 
	Project will defne functions that manipulate arrays that each take in at least the arguments: 
		1. string[]
		2. number of elements to consider (can't be negative)
	If argument string "target" is used, target can be blank, i.e. ""
*/


// Return the # of strings in the array that equal the target string
int enumerate(const string a[], int n, string target) {
	if (n < 0)
		return -1;

	int numOfMatchedStrings = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == target)
			numOfMatchedStrings++;
	}

	return numOfMatchedStrings;
}

// return the position(starting at 0) of the first string in the array that matches "target"
int locate(const string a[], int n, string target) {
	if (n < 0)
		return -1;

	for (int i = 0; i < n; i++) {
		if (a[i] == target)
			return i;
	}

	return -1; // No strings in array matched target
}

// Sets the variables "begin" and "end" passed in equal to the position where the target string is first and last found in the array.
// If no matches are found, return false and don't modify the variables. If at least one match is found, return true and modify both variables.
bool locateSequence(const string a[], int n, string target, int& begin, int& end) {
	if (n < 0)
		return false;

	int firstMatchedStringPos = locate(a, n, target);
	int lastMatchedStringPost = 0;

	if (firstMatchedStringPos != -1)
		lastMatchedStringPost = 

	for (int i = firstMatchedStringPos; i < n; i++) {
		if (a[i] == target) {
			numOfMatchedStrings++;
			if (numOfMatchedStrings == 1)
				begin = i;
		}
	}

	if (numOfMatchedStrings > 0){
		if (numOfMatchedStrings > 1) 

	}

	return false; // No strings in array matched target
}

int main() {
	string array[] = { "hello", "cat", "dog" };
	int beginPos;
	int endPos;

	cout << locateSequence(array, -1, "cat", beginPos, endPos) << endl;
	cout << beginPos << endl;
	cout << endPos << endl;
}