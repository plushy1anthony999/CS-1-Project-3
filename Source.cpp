#include <iostream>
#include <string>
#include <cassert>

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

	if(locate(a, n, target) != -1)
		begin = locate(a, n, target);
	else
		return false; // No matches found using locate()


	for (int i = begin; i < n; i++) {
		if (a[i] == target) 
			end = i; // Will update variable for each match, ending with the position of the last match
	}

	return true; // At least one match found
}

// Returns position of a string in the array that's <= every other string. If that string appears multiple times, return its first appearance
int locationOfMin(const string a[], int n) {
	if(n <= 0)
		return -1;
	
	int smallestStringPos = 0;
	
	for(int i = 0; i < n; i++) {
		if(a[i] < a[smallestStringPos]) {
			smallestStringPos = i;
		}
	}
	
	return smallestStringPos;
}

// Moves an element at position "pos" to end of array, and returns its original position
int moveToEnd(string a[], int n, int pos) {
	if (pos > n - 1)
		return -1;
	
	for(int i = pos; i < n; i++) {
		a[i] = a[i + 1];
	}
	
	return pos;
}

// TODO:
// ?? What's the point of "n" here?
// Moves an element at position "pos" to start of array, and returns its original position
int moveToBeginning(string a[], int n, int pos) {
	if(pos >= n) // since n is a number of elements, n should never be equal to pos
		return -1;
		
	string stringToMove = a[pos];

	for(int i = pos; i > 0; i--) {
		a[i] = a[i - 1];
	}
	
	a[0] = stringToMove;
	return pos;
}

// Returns position of the first corresponding element from both arrays that isn't equal
// n1 and n2 are the number of elements to consider from the arrays respectively
// If both array's elements are equal up until one or both run out, return position of the last element in the shorter array
int locateDifference(const string a1[], int n1, const string a2[], int n2) {
	int indexToReadUpTo;
	
	n1 < n2 ? // uses the shorter value "n" as the stopping point for reading both arrays
		indexToReadUpTo = n1 : 
		indexToReadUpTo = n2;
		
	for(int i = 0; i < indexToReadUpTo; i++) {
		if(a1[i] != a2[i])
			return i;
	}
}

// Modifies array so that it doesn't contain duplicate adjecent elements
// Returns number of elements in the modified array
int eliminateDups(string a[], int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] == a[i + 1]) {
			cout << "Duplicate element: " << a[i] << endl;

			int numOfAdjacentDuplicates = 0; // If an element has duplicates next to it, how many duplicates are next to it?
											 // i.e. if there are 4 "dog" elements, there are 3 duplicates/extras
	
			// Counts duplicates from the current i value until a non-duplicate value is found
			for (int j = i; a[j] == a[j + 1]; j++)
				numOfAdjacentDuplicates++;

			

			cout << "numOfAdjacentDuplicates: " << numOfAdjacentDuplicates << endl;
			i += numOfAdjacentDuplicates - 1; // Makes for loop just to the element after all the duplicates
			
			//// Number of duplicates have been found, so destroy duplicates and
			//// shift elements to the right of the duplicates remaining
			//for(int k = 0; k < numOfAdjacentDuplicates; k++) {
			//	a[i + numOfAdjacentDuplicates + k] = a[i + numOfAdjacentDuplicates + k + 1];
			//}
		}
	}

	return 0; // TODO: fix return value
}

int main() {
	// enumerate() Test	
	string enumerateArray[] = { "cat", "cat", "pig", "bunny" };
	assert(enumerate(enumerateArray, 4, "cat") == 2);
	assert(enumerate(enumerateArray, 1, "cat") == 1);
	assert(enumerate(enumerateArray, 4, "pig") == 1);
	assert(enumerate(enumerateArray, 4, "clown") == 0);

	// locate() Test
	string locateArray[] = { "cat", "cat", "pig", "bunny" };
	assert(locate(locateArray, 1, "cat") == 0);
	assert(locate(locateArray, 0, "cat") == -1);
	assert(locate(locateArray, 0, "duck") == -1);
	assert(locate(locateArray, 4, "cat") == 0);

	// locateSequence() Test
	string locateSequenceArray[] = { "cat", "cat", "pig", "pig", "bunny", "duck" };
	int begin;
	int end;
	assert(locateSequence(locateSequenceArray, 6, "cat", begin, end) == true);
	assert(begin == 0 && end == 1);
	assert(locateSequence(locateSequenceArray, 1, "cat", begin, end) == true);
	assert(begin == 0 && end == 0);
	assert(locateSequence(locateSequenceArray, 3, "pig", begin, end) == true);
	assert(begin == 2 && end == 2);
	assert(locateSequence(locateSequenceArray, 3, "dog", begin, end) == false);
	assert(begin == 2 && end == 2);

	// locationOfMin() Test
	string locationOfMinArray[] = { "cat", "pig", "dog", "dog", "cat", "duck" };
	assert(locationOfMin(locationOfMinArray, 6) == 0);
	string locationOfMinArray2[] = { "duck", "pig", "dog", "dog", "cat", "duck" };
	assert(locationOfMin(locationOfMinArray2, 6) == 4);
	string locationOfMinArray3[] = { "cat", "bird", "dog", "dog", "cat", "duck" };
	assert(locationOfMin(locationOfMinArray3, 6) == 1);
	string locationOfMinArray4[] = { "pig", "pig", "dog", "dog", "dragon", "duck" };
	assert(locationOfMin(locationOfMinArray4, 2) == 0);

	// moveToEnd() Test
	string moveToEndArray[] = { "cat", "pig", "dog", "dog", "cat", "duck" };
	string originalArray[] = { "cat", "pig", "dog", "dog", "cat", "duck" }; // used for testing, won't be modified by moveToEnd()

	assert(moveToEnd(moveToEndArray, 6, 2) == 2);
	assert(moveToEndArray[2] == "dog");
	assert(moveToEndArray[3] == "cat");
	assert(moveToEndArray[4] == "duck");
	assert(moveToEndArray[5] == "dog");
	assert(moveToEnd(moveToEndArray, 6, 5) == 5);

	//assert(moveToEndArray[0] == originalArray[0]);
	//assert(moveToEndArray[1] == originalArray[1]);
	//assert(moveToEndArray[2] == originalArray[2]);
	//assert(moveToEndArray[3] == originalArray[3]);
	//assert(moveToEndArray[4] == originalArray[4]);
	//assert(moveToEndArray[5] == originalArray[5]);
	///*for (int i = 0; i < 6; i++)
	//	assert(moveToEndArray[i] == originalArray[i]);*/

	//// moveToBeginning() Test
	// const int NUM_OF_ELEMENTS = 5;
	// string array[] = {"dog", "cat", "pig", "bunny", "penguin"};
	//
	// assert(moveToBeginning(array, NUM_OF_ELEMENTS, 4) == 4);
	//
	// for(int i = 0; i < 5; i++) {
	// 	cout << array[i] << endl;
	// }
	//
	// cout << "All tests succeeded" << endl;
	//
	// locateDifference() Test
	// string array1[] = {"dog", "bunny", "pig", "duck", "bear", "goldfish"};
	// string array2[] = {"dog", "bunny", "pig", "duck", "bear", "goldfish"};
	//
	// cout << locateDifference(array1, 6, array2, 6) << endl;.

	//string array3[] = {"dog", "cat", "dog", "dog", "dog", "dog", "dog", "cat", "cat", "bunny"};

	//cout << eliminateDups(array3, 10) << endl;
	///*for(int i = 0; i < 10; i++) {
	//	cout << array3[i] << endl;
	//}*/
	
}