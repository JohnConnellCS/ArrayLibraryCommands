#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int reduplicate(string a[], int n);
int locate(const string a[], int n, string target);
int locationOfMax(const string a[], int n);
int circleLeft(string a[], int n, int pos);
int enumerateRuns(const string a[], int n);
int flip(string a[], int n);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int locateAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

int main()
{

}

int reduplicate(string a[], int n) {
	if (n < 0) {
		return -1; //invalid number of elements
	}
	for (int index = 0; index < n; index++) {
		a[index] += a[index]; 
	}
	return n;
}


int locate(const string a[], int n, string target) {
	if (n < 0) {
		return -1; //invalid number of elements
	}
	for (int index = 0; index < n; index++) {
		if (a[index] == target) { //loops through each element of the array until the target is found or index n-1 is reached)
			return index;
		}
	}
	return -1; //target not found
}


int locationOfMax(const string a[], int n) {
	if (n <= 0) {
		return -1; //no maximum if no values examined
	}
	string maxValue = a[0];
	int maxIndex = 0;
	for (int index = 0; index < n; index++) {
		if (a[index] > maxValue) { //increments through the array marking the value and index everytime a new max is found
			maxValue = a[index];
			maxIndex = index;
		}
	}
	return maxIndex;
}


int circleLeft(string a[], int n, int pos) {
	if (n < 0) {
		return -1; //invalid array size
	}
	if (pos >= n || pos < 0) {
		return -1; //position outside size of array
	}
	string temp = a[pos];
	for (int index = pos; index < n-1; index++) { //moves all elements to the right of index pos one to the left
		a[index] = a[index + 1];
	}
	a[n - 1] = temp; //reinserts the value of index pos at the end using a variable to hold its value
	return pos;
}


int enumerateRuns(const string a[], int n) {
	if (n < 0) {
		return -1; //invalid array size
	}
	if (n == 0){
		return 0;
		}
	string current = a[0];
	int counter = 1;
	for (int index = 0; index < n; index++) { 
		if (a[index] != current) { //notes each time a new run(different string) is found
			counter++;
			current = a[index]; //updates the current run string for next comparisons
		}
	}
	return counter;
}


int flip(string a[], int n) {
	if (n < 0) {
		return -1; //invalid array size
	}
	for (int index = 0; index < n/2; index++) {  //increments from outermost pair to innermost pair
		string temp = a[index]; //stores the value on the left side so that it can be overridden
		a[index] = a[n - 1 - index]; //overrides left side value with right side
		a[n - 1 - index] = temp; //uses temporary value to replace right side with left side value
	}
	return n;
}


int locateDifference(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0) {
		return -1; //invalid array size
	}
	int counter = 0;
	while (counter < n1 && counter < n2) { //increments through strings until a difference is found or a length is reached
		if (a1[counter] != a2[counter]) {
			return counter;
		}
		counter++;
	}
	if (n1 <= n2) { //returns whichever length caused the while loop to be broken out of
		return n1;
	}
	else {
		return n2;
	}
}


int subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 < 0) {
		return -1;
	}
	if (n2 == 0) {
		return 0; //any sequence immediately fulfills this case
	}
	for (int index = 0; index < n1 - n2 + 1; index++) {
			if (a1[index] == a2[0]) { //finds first point in a1 where a2[0] is present
				int storeIndex = index;
				bool isSame = true;
				for (int sequence = 0; sequence < n2; sequence++) { //increments through both strings comparing equality
					if(a2[sequence] != a1[index]){
						isSame = false; //if any a1 differs from a2 the loop will no longer return the stored index
					}
					index++;
				}
				if (isSame) {
					return storeIndex;
				}
			}
	}
	return -1;
}


int locateAny(const string a1[], int n1, const string a2[], int n2) {
	if (n1 < 0 || n2 <= 0) {
		return -1;
	}
	int currentMin = n1;
	for (int index = 0; index < n1; index++) {
		for (int indexTwo = 0; indexTwo < n2; indexTwo++) { //checks each string in a1 with the entirety of a2
			if (a1[index] == a2[indexTwo]) { //if any matches are found, the index of a1 is returned
				if (index < currentMin) {
					currentMin = index;
				}
			}
		}
	}
	if (currentMin != n1) {
		return currentMin;
	}
	return -1; // no element found
}


int divide(string a[], int n, string divider) {
	if (n < 0) {
		return -1; //invalid array size
	}
	int currentIndex = 0;
	for (int index = 0; index < n; index++){ //use selection sort to arrange values from lowest to greatest
		int minimumIndex = currentIndex;
		for (int findMin = currentIndex; findMin < n; findMin++) { //start incrementing through the unsorted strings
			if (a[findMin] < a[minimumIndex]) {
				minimumIndex = findMin; //find minimum on the bounds currentIndex to n-1
			}
		}
		string temp = a[currentIndex];
		a[currentIndex] = a[minimumIndex];
		a[minimumIndex] = temp;
		currentIndex++; //everything to the left of currentIndex is sorted
	}
	for (int index = 0; index < n; index++) { //find first string equal or greater than divider then return it
		if (a[index] >= divider) {
			return index;
		}
	}
	return n; //return n if no values greater than or equal to the divider are found
}

