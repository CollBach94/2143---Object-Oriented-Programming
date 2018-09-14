#include <iostream>
#include "myVector.h"

using namespace std;

/**
*  Creates the first vector that will be used in the program.
*
*
* @param {int size} The initial size the vector will be
* @return {myVector} The vector that will be used in the program.
*/
myVector::myVector(int size) {
	vSize = size;				//Make vSize the input size.
	OrSize = vSize;				//Copy original vSize to OrSize.
	theVector = new int[vSize];
	//just so we have stuff to print!!!!!
	//for (int i = 0; i<vSize; i++) {
	//theVector[i] = i * 2;

	//}
}

/**
*  Adds a selected value onto the end of the vector.
*
*
* @param {int val} The value that will be added to the end of the vector.
* @return {void}
*/
void myVector::Push_Back(int Val) {
	theVector[Index++] = Val;
	//Check to see if Index is filled and needs more space.
	if (Index >= vSize) {
		//cout << "Making Big..." << endl;
		MakeBig(theVector, vSize);
	}
}

/**
*  For this program, rejects the string because the 
*  vector only accepts integers.
*
*
* @param {string Text} The string attempting to be passed into the vector
* @return {void}
*/
void myVector::Push_Back(string Text) {
	cout << "Sorry, you cannot add strings to a integer only vector. ";
	cout << endl;
	return;
}
/**
*  Adds a number of values to the end of the vector.
*
*
* @param {int val} The number of times values will be added to the end of a vector.
* @return {void}
*/
void myVector::PushRand(int Number) {
	for (int i = 0; i < Number; i++) {
		theVector[Index++] = (rand() % 100);
		//If there is no more room to place data, then call MakeBig.
		if (Index > vSize) {
			//cout << "Making Big..." << endl;
			MakeBig(theVector, vSize);
			//printSize();
		}
	}
	return;
}

/**
* Sets Index back once, "popping" the vector.
*
*
* @param {}
* @return {void}
*/
void myVector::Pop_Back() {
	//Error check to prevent popping off an empty vector
	//Pop out of the function if there is no data
	if (Index <= 0) {
		cout << "ERROR! The Vector is empty!" << endl;
		return;
	}
	Index--;
	if (Index < (vSize * .4) && vSize > OrSize) {
		MakeSmall(theVector, vSize);
	}
}

/**
* Sets Index back however many times indicated
*
*
* @param {int Rounds} However many times Index will be pushed back.
* @return {void}
*/
void myVector::Pop_BackMult(int Rounds) {
	//Error check to prevent popping off an empty vector
	//Pop out of the function if there is no data
	if (Index <= 0) {
		cout << "ERROR! The Vector is empty!" << endl;
		return;
	}

	for (int i = 0; i< Rounds; i++) {
		Index--;
		//Check to see if the array needs to be made smaller
		if (Index < (vSize * .4) && vSize > OrSize) {
			MakeSmall(theVector, vSize);
			//printSize();
		}

	}
	return;
}

/**
*  Creates a new vector with more space that the old vector will be copied to.
*
*
*
* @param {int *a} The vector that is being passed through.
* @param {int size} The current size of the vector.
* @return {int}
*/
//Makes the vector bigger when needed.
int* myVector::MakeBig(int *a, int size) {
	//Update the size of vSize.
	vSize = vSize * 1.5;
	//Increasing the size of the array by 1.5 times.
	int NewSize = size * 1.5;
	int* NewVector;
	//Create a new vector with the NewSize.
	NewVector = new int[NewSize];
	//Filling the array with 0.
	for (int i = 0; i < NewSize; i++) {
		NewVector[i] = 0;
	}
	for (int i = 0; i < Index; i++) {
		NewVector[i] = theVector[i];
	}
	//This is supposed to delete the old vector to free up memory
	//delete[] theVector;
	theVector = NewVector;
	//system("pause");
	return NewVector;
}

/**
*  Creates a new vector with less space that the old vector will be copied to.
*  The new array will be .40 the size of the old vector.
*
*
* @param {int *a} The vector that is being passed through.
* @param {int size} The current size of the vector.
* @return {int}
*/
int* myVector::MakeSmall(int *a, int size) {
	vSize = vSize * 0.5;
	int NewSize = size * 0.5;
	if (vSize < OrSize) {
		NewSize = OrSize;
		vSize = OrSize;
	}
	int* NewVector;
	NewVector = new int[NewSize];
	//Filling the vector with 0.
	for (int i = 0; i < NewSize; i++) {
		NewVector[i] = 0;
	}
	//Copying old vector to new vector until filled.
	for (int i = 0; i < NewSize; i++) {
		NewVector[i] = theVector[i];
	}
	//This is supposed to delete the old vector to free up memory
	//delete[] theVector;
	theVector = NewVector;
	//system("pause");
	return NewVector;
}

/**
*  Prints out all of the data in a vector in order.
*
*
* @param {}
* @return {void}
*/
void myVector::print() {
	for (int i = 0; i<Index; i++) {
		cout << theVector[i] << " ";
	}
	cout << endl;
	return;
}

/**
*  Prints out the size of the vector.
*
*
* @param {}
* @return {void}
*/
void myVector::printSize() {
	cout << "The current array size is " << vSize << "." << endl;
	return;
}

/**
*  Prints out the current Index.
*
*
* @param {}
* @return {void}
*/
void myVector::printIndex() {
	cout << "The current index (number of data) is " << Index << "." << endl;
	return;
}
