/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Utilize the concept of overloading to modify the vectors
*  in a variety of ways. Specifically, the operators +, -, *, /, =, and ==
*  are not only overloaded to calculate two vectors, but can, if necessary,
*  modify vectors by using single values and arrays, if required.
*
*  @author Collin Bachman
*  @version 1.0 10/1/18
*  @github repo: https://github.com/CollBach94
*/

#include <iostream>
#include <fstream>
#include "myVector.h"

using namespace std;


int main() {
	ofstream outfile;
	outfile.open("output.txt");

	myVector V(10);

	for (int i = 0; i < 501; i++) {
		V.pushBack(rand() % 100);
	}

	myVector v1(10);
	myVector v2(10);

	v1.pushBack(8);
	// v1 contains: [8]

	v2.pushBack(10);
	v2.pushBack(20);
	v2.pushBack(30);
	// v2 contains: [10,20,30]

	// Declare some int array
	int A[] = { 1,2,3,4,5 };


	v1.pushBack(A, 5);
	// v1 contains: [8,1,2,3,4,5]
	outfile << v1 << endl;
	outfile << "adding 2 Vectors" << endl;
	v1 = v1 + v2;
	// v1 contains: [18,21,32,3,4,5]
	outfile << "Printing v1..." << endl;
	outfile << v1 << endl;
	outfile << "Printing v2..." << endl;
	outfile << v2 << endl;
	// would print: [18,21,32,3,4,5] to standard out.
	outfile << "v1[2] should be 32. It is..." << endl;
	outfile << v1[2] << endl;
	// would print: 32 to standard out.
	outfile << "Subtracting v1 from v2" << endl;
	v1 = v1 - v2;
	outfile << "v1[2] should be 2. It is..." << endl;
	outfile << v1[2] << endl;
	outfile << "reverting v1..." << endl;
	v1 = v1 + v2;

	v2 = v2 * 3;
	// v2 contains: [30,60,90]
	outfile << "Printing the multiplied v2 by 3" << endl;
	outfile << v2 << endl;
	v2 = v2 * v1;
	outfile << "Printing the multiplied v2 by v1" << endl;
	// v2 contains: [540,1260,2880]
	outfile << v2 << endl;

	v2[2] = 100;
	// v2 contains: [540,1260,100]
	outfile << "v2[2] should now contain 100" << endl;
	outfile << v2 << endl;


	outfile << "Is v1 = v2?" << endl;
	outfile << bool(v1 == v2) << endl;;
	outfile << "Create v3, and make it equal to v2" << endl;
	myVector v3 = v2;
	outfile << "just for fun, does v3 = v2?" << endl;
	outfile << bool(v3 == v2) << endl;;
	v3 = v3 / v2;
	outfile << "Since v3 and v2 are equal, v3/v2 should be all 1s" << endl;
	outfile << v3 << endl;
	outfile << "Now let's add v2 to the end of v3" << endl;
	v3.pushBack(v2);
	outfile << "Now lets see the new v3" << endl;
	outfile << v3 << endl;
	//system("pause");
	return 0;
}
