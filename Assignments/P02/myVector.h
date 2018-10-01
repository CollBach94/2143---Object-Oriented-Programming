#include <iostream>

using namespace std;

class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	myVector(int size);
	void pushBack(int item);
	void pushBack(int *A, int size);
	void pushBack(myVector Add);
	int popBack();
	double percentFull();
	int* resize(double);
	int* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

	/**
	*  Overload that fetches a single array element to return.
	*  The array element that is returned depends on the value passed in.
	*
	*  @param {int} digit that is used as the array's index.
	*  @return {int&} the pointer to the array's element
	*/
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			system("pause");
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}

	/**
	*  Overload that adds 2 vectors. The vector passed in will be added
	*  to the preceding vector by index (A[1] + B[1]) as  long as the
	*  second vectors have values to pass in.
	*
	*  @param {myVector&} vector that will be added to the first vector.
	*  @return {myVector} the new vector that is the sum of the 2 vectors.
	*/
	myVector operator+(const myVector& Rhs)
	{
		int size = 0;			//size for our loop
		//check to see how much data there is in both vectors
		//the smallest size will be used.
		if (index <= Rhs.index) {	
			size = index;
		}
		else if (index > Rhs.index) {
			size = Rhs.index;
		}
		//Calculations
		for (int i = 0; i < size; i++) {
			vPtr[i] += Rhs.vPtr[i];
		}
		myVector Temp(10);	//The new vector that will carry over values
		Temp.index = 0;			//Setting index to prevent errors.
		for (int i = 0; i < index; i++) {
			Temp[Temp.index++] = 0;
			
		}
		for (int i = 0; i < index; i++) {
			Temp[i] = vPtr[i];
		}
		return Temp;
	}

	/**
	*  Overload that subtracts 2 vectors. The vector passed in will be 
	*  subtracted to the preceding vector by index (A[1] - B[1]) as long as
	*  the second vectors have values to pass in.
	*
	*  @param {myVector&} vector that will be subtracted 
	*					  from the first vector.
	*  @return {myVector} the new vector that is the difference
	*					  of the 2 vectors.
	*/
	myVector operator-(const myVector& Rhs)
	{
		int size = 0;			//size for our loop
								//check to see how much data 
								// there is in both vectors
								//the smallest size will be used.
		if (index <= Rhs.index) {
			size = index;
		}
		else if (index > Rhs.index) {
			size = Rhs.index;
		}
		//Calculations
		for (int i = 0; i < size; i++) {
			vPtr[i] -= Rhs.vPtr[i];
		}
		myVector Temp(10);	//The new vector that will carry over values
		Temp.index = 0;			//Setting index to prevent errors.
		for (int i = 0; i < index; i++) {
			Temp[Temp.index++] = 0;

		}
		for (int i = 0; i < index; i++) {
			Temp[i] = vPtr[i];
		}
		return Temp;
	}

	/**
	*  Overload that multiplies elements in a vector by a number.
	*  Each element will be treated as (A[i] * j).
	*
	*  @param {int} The number that will be used to multiply the vector
	*  @return {myVector} the new vector that is the product
	*					  of the vector and number
	*/
	myVector operator*(const int Mult)
	{
		int size = index;	//for defining how amny times to loop
		//Calculations
		for (int i = 0; i < size; i++) {
			vPtr[i] *= Mult;
		}
		myVector Temp(10);
		Temp.index = 0;
		for (int i = 0; i < index; i++) {
			Temp[Temp.index++] = 0;

		}
		for (int i = 0; i < index; i++) {
			Temp[i] = vPtr[i];
		}
		return Temp;
	}

	/**
	*  Overload that multiplies 2 vectors. The vector passed in will be
	*  subtracted to the preceding vector by index (A[1] * B[1]) as long as
	*  the second vectors have values to pass in.
	*
	*  @param {myVector&} vector that will be multiplied to the first vector.
	*  @return {myVector} the new vector that is the product
	*					  of the 2 vectors.
	*/
	myVector operator*(const myVector& Rhs)
	{
		int size = 0;			//size for our loop
								//check to see how much data there is 
								// in both vectors
								//the smallest size will be used.
		if (index <= Rhs.index) {
			size = index;
		}
		else if (index > Rhs.index) {
			size = Rhs.index;
		}
		//Calculations
		for (int i = 0; i < size; i++) {
			vPtr[i] *= Rhs.vPtr[i];
		}
		myVector Temp(10);	//The new vector that will carry over values
		Temp.index = 0;			//Setting index to prevent errors.
		for (int i = 0; i < index; i++) {
			Temp[Temp.index++] = 0;

		}
		for (int i = 0; i < index; i++) {
			Temp[i] = vPtr[i];
		}
		return Temp;
	}

	/**
	*  Overload that divides 2 vectors. The vector passed in will be
	*  subtracted to the preceding vector by index (A[1] / B[1]) as long as
	*  the second vectors have values to pass in.
	*
	*  @param {myVector&} vector that will be divided from the first vector.
	*  @return {myVector} the new vector that is the quotient
	*					  of the 2 vectors.
	*/
	myVector operator/(const myVector& Rhs)
	{
		int size = 0;			//size for our loop
								//check to see how much data there is 
								//in both vectors
								//the smallest size will be used.
		if (index <= Rhs.index) {
			size = index;
		}
		else if (index > Rhs.index) {
			size = Rhs.index;
		}
		//Calculations
		for (int i = 0; i < size; i++) {
			vPtr[i] /= Rhs.vPtr[i];
		}
		myVector Temp(10);	//The new vector that will carry over values
		Temp.index = 0;			//Setting index to prevent errors.
		for (int i = 0; i < index; i++) {
			Temp[Temp.index++] = 0;

		}
		for (int i = 0; i < index; i++) {
			Temp[i] = vPtr[i];
		}
		return Temp;
	}

	/**
	*  Overload that compares 2 vectors. It compares the indeces of each
	*  vector before comparing each element in the array. 
	*
	*  @param {myVector&} vector that will be compared to the first vector.
	*  @return {bool} the result of if the 2 vectors are equal.
	*/
	bool operator==(const myVector& Rhs)
	{
		//Check to see if the vectors are the same size.
		if (index != Rhs.index) {
			//std::cout << "FALSE. INDEX MISMATCH" << endl;
			return false;
		}
		//Comparing all of the elements in both vectors
		for (int i = 0; i < index; i++) {
			if (vPtr[i] != Rhs.vPtr[i]) {
				//std::cout << "FALSE. VALUE MISMATCH" << endl;
				return false;
			}
		}
		//std::cout << "TRUE. BOTH EQUAL" << endl;
		return true;
	}

	/**
	*  Overload that prints out the elements in a vector sequentially
	*
	*  @param {ostream&} Allows the function to print to the screen
			  {myVector&} vector that will be printed out
	*  @return {ostream&} return the ostream
	*/
	friend ostream& operator<<(ostream& os, myVector V) {
		for (int i = 0; i<V.index; i++) {
			os << V.vPtr[i] << " ";
		}
		//os<<"test"<<endl;
		return os;
	}
};


/**
* Function constructor
*   Sets up the vector
* @param {int} size : initial size of vector
* @return void
*/
myVector::myVector(int size) {
	maxSize = size;
	minSize = size;
	// create the array of vSize
	vPtr = new int[maxSize];
	index = 0;
}

/**
* Function print
*   Prints the current values in the vector
* @param void
* @return void
*/
void myVector::print() {
	for (int i = 0; i<index; i++) {
		cout << vPtr[i] << " ";
	}
	cout << endl;
}

/**
* Function pushBack
*   Adds value to vector
* @param {int} item : integer value
* @return void
*/
void myVector::pushBack(int item) {
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	vPtr[index++] = item;
}

/**
*  Overload that compares 2 vectors. It compares the indeces of each
*  vector before comparing each element in the array.
*
*  @param {myVector&} vector that will be compared to the first vector.
*  @return {bool} the result of if the 2 vectors are equal.
*/
void myVector::pushBack(int *A, int size) {
	int aCount = 0;
	if (index >= maxSize) {
		vPtr = resize(1.5);
	}
	while (aCount < size) {
		vPtr[index++] = A[aCount];
		aCount++;
	}
	return;
}

/**
*  Overload thats supposed to append one vector to the end of anouther
*
*  @param {myVector} vector that will be appended
*  @return {void}
*/
void myVector::pushBack(myVector Add) {
	for (int i = 0; i < Add.index; i++) {
		vPtr[index++] = Add.vPtr[i];
		if (index >= maxSize) {
			vPtr = resize(1.5);
		}
	}
	return;
}

/**
* Function popBack
*   Returns value from vector
* @param none
* @return {int} : last item on vector
*/
int myVector::popBack() {

	index--;

	if (index < 0) {
		//dammit
	}

	if (percentFull() <= .4) {
		vPtr = resize(.5);
	}

	return vPtr[index];
}

/**
* Function resize
*   Resizes our vector based on passed in ratio
* @param {double} ratio : new array size
* @return {int*} : pointer to new array
*/
int* myVector::resize(double ratio) {
	// figure out what our new size is, bigger or smaller
	int newSize = maxSize * ratio;

	return _resize(newSize);
}


int* myVector::resize(int size) {

	return _resize(size);

}

int* myVector::_resize(int newSize) {
	// Lets keep our vector above some minimum size
	if (newSize < minSize) {
		newSize = minSize;
	}

	// allocate new bigger vector
	int* vBigger = new int[newSize];

	//copy everything over
	for (int i = 0; i<index; i++) {
		vBigger[i] = vPtr[i];
	}

	// update new max size
	maxSize = newSize;

	// delete old memory
	delete[] vPtr;

	//return ptr to new memory
	return vBigger;
}

/**
* Function percentFull
*   helper function to calculate how full vector is
* @param none
* @return {double} : how full vector is
*/
double myVector::percentFull() {
	return double(index) / double(maxSize);
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
int myVector::size() {
	return index;
}

/**
* Function size
*    Returns number of current items in vector
* @param none
* @return {int} : num items
*/
void myVector::size(int newSize) {
	vPtr = _resize(newSize);
}

/**
* Function vSize
*    Returns actual size of allocated memory
* @param none
* @return {int} : mem size
*/
int myVector::vSize() {
	return maxSize;
}


