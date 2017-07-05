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
		if(a[i] < a[smallestStringPos])
			smallestStringPos = i;		
	}
	
	return smallestStringPos;
}

// Moves an element at position "pos" to end of array, and returns its original position
int moveToEnd(string a[], int n, int pos) {
	if(pos >= n) // since n is a number of elements, n should never be equal to pos
		return -1;
	if(pos == n - 1) // if the element to be moved is already at the end
		return pos;
	
	for(int i = pos; i < n; i++) {
		if(i != n - 1) // handles each element except the last
			a[i] = a[i + 1];
		
		else if(i == n - 1) // handles last element and prevents access to elements outside the array
			a[i] = a[pos];
	}
	
	return pos;
}

// TODO:
// ?? What's the point of "n" here?
// ?? Do I need to handle a negative pos being passed in?
// Moves an element at position "pos" to start of array, and returns its original position
int moveToBeginning(string a[], int n, int pos) {
	if(pos >= n) // since n is a number of elements, n should never be equal to pos
		return -1;
	if(pos == 0) // if the element to be moved is already at the beginning
		return pos;
		
	string stringToMove = a[pos];

	for(int i = pos; i > 0; i--)
		a[i] = a[i - 1];

	a[0] = stringToMove;
	return pos;
}

// Returns position of the first corresponding element from both arrays that isn't equal
// n1 and n2 are the number of elements to consider from the arrays respectively
// If both array's elements are equal up until one or both run out, return position of the last element in the shorter array
int locateDifference(const string a1[], int n1, const string a2[], int n2) {
	if(n1 < 0 || n2 < 0)
		return -1;
	
	int indexToReadUpTo;
	
	n1 < n2 ? // uses the shorter value "n" as the stopping point for reading both arrays
		indexToReadUpTo = n1 : 
		indexToReadUpTo = n2;
		
	for(int i = 0; i < indexToReadUpTo; i++) {
		if(a1[i] != a2[i])
			return i;
	}
}

// TODO: Do I need to handle n being bigger than the array size?
// Modifies array so that it doesn't contain duplicate adjecent elements
// Returns number of elements in the modified array
int eliminateDups(string a[], int n) {
	if (n < 0)
		return -1;

	int arraySize = n; // Track size of array as elements are removed

	for(int i = 0; i < arraySize; i++) { // by tracking the modified array's size, I won't read duplicate elements that were already moved
		if (i == arraySize - 1) // handle last element, which doesn't need to be moved
			break;

		string firstElement = a[i]; // firstElement is the first value in a list of duplicate values 
		int firstElementIndex = i;  // i.e. the first "dog" in a list of 4 consecutive "dog" elements

		if (a[firstElementIndex] == a[firstElementIndex + 1]) {

			// Counts duplicates from the current i value until a non-duplicate value is found
			// Makes sure loop doesn't read past the array boundary
			while ((firstElementIndex != arraySize - 1) && (a[firstElementIndex] == a[firstElementIndex + 1])) { 
				moveToEnd(a, arraySize, firstElementIndex);
				arraySize--;
			}
		}
	}

	return arraySize;
}

// Returns true if al n2 elements of a2 appear in a1 in the same order, but the elements don't need to be consecutive
// Return false otherwise
bool subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0)
		return false;
	if (n2 == 0) // Asks "is there an empty sequence in a2?", which is always true
		return true;
	if (n1 < n2) // Could ask "do these 3 elements appear in this 2 element array," which would always be false
		return false;

	for (int i = 0; i < n2; i++) { // Counts through the sub-array i.e. a2
		for (int k = 0; k < n1; k++) { // Counts through the main-array i.e. a1

		}

	}

	//for (int i = 0; i < n1; i++) { // Counts through the main-array i.e. a1
	//	for (int k = 0; k < n2; k++) { // Counts through the sub-array i.e. a2
	//		if(a1[i] == a2[k])
	//	}
	//}
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
	string locationOfMinArray1[] = { "cat", "pig", "dog", "dog", "cat", "duck" };
	string locationOfMinArray2[] = { "duck", "pig", "dog", "dog", "cat", "duck" };
	string locationOfMinArray3[] = { "cat", "bird", "dog", "dog", "cat", "duck" };
	string locationOfMinArray4[] = { "pig", "pig", "dog", "dog", "dragon", "duck" };
	
	assert(locationOfMin(locationOfMinArray1, 6) == 0);
	assert(locationOfMin(locationOfMinArray2, 6) == 4);
	assert(locationOfMin(locationOfMinArray3, 6) == 1);
	assert(locationOfMin(locationOfMinArray4, 2) == 0);


	// moveToEnd() Test
	string moveToEndArray1[] = { "cat", "pig", "dog", "dog", "cat", "duck" };
	string moveToEndArray2[] = { "cat", "pig", "dog", "dog", "cat", "duck" };

	string originalMoveToEndArray[] = { "cat", "pig", "dog", "dog", "cat", "duck" }; // used for testing, won't be modified by moveToEnd()

	assert(moveToEnd(moveToEndArray1, 6, 2) == 2); // Modify Test Array 1
	assert(moveToEndArray1[2] == "dog");
	assert(moveToEndArray1[3] == "cat");
	assert(moveToEndArray1[4] == "duck");
	assert(moveToEndArray1[5] == "dog");
	
	assert(moveToEnd(moveToEndArray2, 6, 5) == 5); // Modify Test Array 2
	for (int i = 0; i < 6; i++) // Tests if Test Array 2 has been unchanged compared to the original array
		assert(moveToEndArray2[i] == originalMoveToEndArray[i]);
	
	
	// moveToBeginning() Test
	string moveToBeginningArray1[] = {"dog", "cat", "pig", "bunny", "penguin"};
	string moveToBeginningArray2[] = {"dog", "cat", "pig", "bunny", "penguin"};
	
	string originalMoveToBeginningArray[] = {"dog", "cat", "pig", "bunny", "penguin"}; // used for testing, won't be modified by moveToBeginning()
	
	assert(moveToBeginning(moveToBeginningArray1, 5, 3) == 3); // Modify Test Array 1;
	assert(moveToBeginningArray1[0] == "bunny");
	assert(moveToBeginningArray1[1] == "dog");
	assert(moveToBeginningArray1[2] == "cat");
	assert(moveToBeginningArray1[3] == "pig");
	assert(moveToBeginningArray1[4] == "penguin");

	assert(moveToBeginning(moveToBeginningArray2, 5, 0) == 0); // Modify Test Array 2;
	for(int i = 0; i < 5; i++) 
		assert(moveToBeginningArray2[i] == originalMoveToBeginningArray[i]); // Tests if Test Array 2 has been unchanged compared to the original array
	
	
	// locateDifference() Test
	string locateDifferenceArray1[] = {"dog", "cat", "pig", "bunny", "penguin"}; // Test 1 //
	string locateDifferenceArray2[] = {"dog", "cat", "cat", "bunny", "penguin"};
	assert(locateDifference(locateDifferenceArray1, 3, locateDifferenceArray2, 5) == 2);

	string locateDifferenceArray3[] = {"dog", "cat", "pig", "bunny", "penguin"}; // Test 2 //
	string locateDifferenceArray4[] = {"dog"};
	assert(locateDifference(locateDifferenceArray3, 5, locateDifferenceArray4, 1) == 1);
	
	string locateDifferenceArray5[] = {"dog", "cat", "pig", "bunny", "penguin"}; // Test 3 //
	string locateDifferenceArray6[] = {"dog", "cat", "pig", "bunny", "penguin"};
	assert(locateDifference(locateDifferenceArray5, 0, locateDifferenceArray6, 1) == 0);
	
	assert(locateDifference(locateDifferenceArray5, -5, locateDifferenceArray6, -1) == -1); // Handles bad arguments being passed
	
	// eliminateDups() Test
	string eliminateDupsArray1[] = { "cat", "cat", "dog", "dog", "dog", "dog", "dog" };
	string eliminateDupsArray2[] = {"cat", "dog", "bunny"};
	string eliminateDupsArray3[] = {"cat", "dog", "bunny", "bunny"};
	string eliminateDupsArray4[] = { "cat", "cat", "dog", "dog", "dog", "dog", "cat" };
	string eliminateDupsArray5[] = { "cat", "cat", "dog", "dog", "dog", "dog", "cat" };
	string eliminateDupsArray6[] = {"cat", "cat", "dog", "dog", "dog", "cat", "cat", "bunny", "bunny"};
	string eliminateDupsArray7[] = {"cat", "cat", "cat", "dog", "penguin", "bunny", "dog"};
	
	assert(eliminateDups(eliminateDupsArray1, 7) == 2);
	assert(eliminateDups(eliminateDupsArray2, 3) == 3);
	assert(eliminateDups(eliminateDupsArray3, 4) == 3);
	assert(eliminateDups(eliminateDupsArray4, 7) == 3);
	assert(eliminateDups(eliminateDupsArray5, -22) == -1);
	assert(eliminateDups(eliminateDupsArray6, 9) == 4);
	assert(eliminateDups(eliminateDupsArray7, 7) == 5);

	assert(eliminateDupsArray1[0] == "cat"); // Array 1
	assert(eliminateDupsArray1[1] == "dog");
	assert(eliminateDupsArray2[0] == "cat"); // Array 2
	assert(eliminateDupsArray2[1] == "dog");
	assert(eliminateDupsArray2[2] == "bunny");
	assert(eliminateDupsArray3[0] == "cat"); // Array 3
	assert(eliminateDupsArray3[1] == "dog");
	assert(eliminateDupsArray3[2] == "bunny");
	assert(eliminateDupsArray4[0] == "cat"); // Array 4
	assert(eliminateDupsArray4[1] == "dog");
	assert(eliminateDupsArray4[2] == "cat");
	assert(eliminateDupsArray5[0] == "cat"); // Array 5
	assert(eliminateDupsArray5[1] == "cat");
	assert(eliminateDupsArray5[2] == "dog");
	assert(eliminateDupsArray5[3] == "dog");
	assert(eliminateDupsArray5[4] == "dog");
	assert(eliminateDupsArray5[5] == "dog");
	assert(eliminateDupsArray5[6] == "cat");
	assert(eliminateDupsArray6[0] == "cat"); // Array 6
	assert(eliminateDupsArray6[1] == "dog");
	assert(eliminateDupsArray6[2] == "cat");
	assert(eliminateDupsArray6[3] == "bunny");
	assert(eliminateDupsArray7[0] == "cat"); // Array 7
	assert(eliminateDupsArray7[1] == "dog");
	assert(eliminateDupsArray7[2] == "penguin");
	assert(eliminateDupsArray7[3] == "bunny");
	assert(eliminateDupsArray7[4] == "dog");
	

	// subsequence() Test
	string subsequenceArray1[] = { "cat", "dog", "dog", "cat", "bunny" };
	string subsequenceArray2[] = { "cat", "penguin", "dog", "bunny" };

	assert(subsequence(subsequenceArray1, -1, subsequenceArray2, 2) == false);


	
	cerr << "All tests succeeded" << endl;
}