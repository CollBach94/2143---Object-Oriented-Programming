#pragma once
#include <iostream>

using namespace std;

//This sets up all of the necessary functions/data for the program.
class myVector {
private:
	int *theVector;	//The Array(Vector) where we store data
	int vSize = 0;	//The size of theVector will be
	int Index = 0;	//A changhing tally of where to add/remove data
	int OrSize = 0;	//Storage container for the original size of the vector
public:
	myVector(int size);
	void Push_Back(int Val);
	void Push_Back(string Text);
	void PushRand(int Number);
	void Pop_Back();
	void Pop_BackMult(int Rounds);
	int* MakeBig(int *a, int size);
	int* MakeSmall(int *a, int size);
	void print();
	void printSize();
	void printIndex();
};
