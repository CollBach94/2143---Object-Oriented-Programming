/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Create a dynamic array that functions similairly to a vector
* 	The main function will add and remove data to the array, and the
* 	array will grow larger if there is more space needed or made smaller
* 	if there is too much open space.
*
*  @author Collin Bachman
*  @version 1.1 09/14/2018
*/

#include <iostream>
#include "myVector.h"
#include <time.h>

using namespace std;

int main() {
	myVector V(10);
	V.print();
	V.printSize();
	V.printIndex();
	V.Pop_Back();
	V.Push_Back(13);
	V.Push_Back(31);
	V.Push_Back(73);
	V.Push_Back("Umm... Hi.");
	V.print();
	V.printSize();
	V.printIndex();
	V.PushRand(10000);	//Using PushRand to add a lot of random integers.
	V.printSize();
	V.printIndex();
	V.Pop_BackMult(9997);	//For popping lots of numbers at once.
	V.print();
	V.printSize();
	V.printIndex();
	V.Pop_Back();
	V.print();
	V.printSize();
	V.printIndex();
	//Trying out Push_Back with a for loop for specified data.
	for (int i = 0; i <= 5; i++) {
		V.Push_Back(i * 4);
	}
	V.print();
	V.printSize();
	V.printIndex();
	for (int i = 0; i <= 3; i++) {
		V.Pop_Back();
	}
	V.print();
	V.printSize();
	V.printIndex();
	system("pause");
	return 0;
}
