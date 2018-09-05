/**
*  Course: CMPS 3013 - Algorithms
*  Assignment: A02
*  Purpose: The program adds the values of two lists into a third list
*  The assignment is to properly comment the code.
*
*  @author Collin Bachman
*  @version 1.1 09/05/2018
*/

#include <iostream>
#include <string>

using namespace std;

//Creates an array with 100 locations
int A[100];

/*
*  Creating a new data type Node.
*/
struct Node
{
	int x;		//Hold an integer of that node
	Node *next;	//Holds reference to the next node in the list
	//Initializes the node.
	Node()
	{
		x = -1;
		next = NULL;
	}
	//Creating a node with a int as data (x). 
	Node(int n)
	{
		x = n;
		next = NULL;
	}
};

/*
*  List defines pointers and functions used in the list(s).
*/
class List
{
private:
	Node * Head;	//Signals the first node of the list
	Node *Tail;		//Signals the last node of the list
	int Size;		//Records the size of the list(s)

public:
	List()
	{
		//Setting Head, Tail, and Size to the appropriate values
		Head = Tail = NULL;
		Size = 0;
	}
	/**
	*  Pushes a single value onto the end of the list.
	*
	*  @param {int} val the number being added to the list.
	*  @return {void}
	*/
	void Push(int val)
	{
		// allocate new memory and init node
		Node *Temp = new Node(val);
		//If there is no data, set Temp as Head and Tail.
		if (!Head && !Tail)
		{
			Head = Tail = Temp;
		}
		//Otherwise, point Tail->Next to Temp, then set Temp as Tail
		else
		{
			Tail->next = Temp;
			Tail = Temp;
		}
		Size++;		//Increase Size by 1.
	}
	/**
	*  Adds a number to the top of the list.
	*
	*  @param {int} val the number being added to the list.
	*  @return {void}
	*/
	void Insert(int val)
	{
		// allocate new memory and init node
		Node *Temp = new Node(val);

		// figure out where it goes in the list

		Temp->next = Head;
		Head = Temp;
		if (!Tail)
		{	//Sets Tail to Head if there is no Tail value.
			Tail = Head;
		}
		Size++;
	}
	/**
	*  Prints out the value that Tail points to in that list to the screen.
	*
	*  @param {NULL}
	*  @return {void}
	*/
	void PrintTail()
	{
		cout << Tail->x << endl;
	}
	/**
	*  Prints out all the data on a list in order.
	*
	*  @param {NULL}
	*  @return {string} The list of values in the list
	*/
	string Print()
	{
		Node *Temp = Head;		
		string list;

		while (Temp != NULL)
		{	//Adds the data and arrow to the list each time.
			list += to_string(Temp->x) + "->";
			Temp = Temp->next;
		}

		return list;
	}

	// not implemented 
	int Pop()
	{
		Size--;
		return 0; //
	}
	/**
	*  Creates a new list using data from other lists.
	*
	*  @param {const List} references to the lists that will be copied.
	*  @return {List} The new list with data from other lists.
	*/
	List operator+(const List &Rhs)
	{
		// Create a new list that will contain both when done
		List NewList;

		// Get a reference to beginning of local list
		Node *Temp = Head;

		// Loop through local list and Push values onto new list
		while (Temp != NULL)
		{
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Get a reference to head of Rhs
		Temp = Rhs.Head;

		// Same as above, loop and push
		while (Temp != NULL)
		{
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Return new concatenated version of lists
		return NewList;
	}
	/**
	*  Implements the [] Operator to allow this function to retrieve data
	*  from a list as if it is an array.
	*
	*  @param {int index} The indexed location to be retrieved from the list
	*  @return {int} The data found at that index.
	*/
	int operator[](int index)
	{
		Node *Temp = Head;
		//Error message for the index being greater than the list Size.
		if (index >= Size)
		{
			cout << "Index out of bounds, exiting";
			exit(0);
		}
		else
		{
			for (int i = 0; i < index; i++)
			{	//Looping to the indexed location.
				Temp = Temp->next;
			}
			//Returns the indexed data once the for loop is finished.
			return Temp->x;
		}
	}
	/**
	*  Calls a print function to print out 
	*
	*  @param {ostream  &os}The indexed location to be retrieved from the list
	*		  {List L} The list that will be used to call the Print function.
	*  @return {friend ostream} The data that will be displayed to the screen.
	*/
	friend ostream &operator<<(ostream &os, List L)
	{
		os << L.Print();	//Call the print fuction with the chosen List.
		return os;
	}
};

int main(int argc, char **argv)
{
	//Creating 2 lists using the List data type
	List L1;
	List L2;

	//For loop that adds i to each L1 node
	for (int i = 0; i < 25; i++)
	{
		//Pushes i into the L1 list.
		L1.Push(i);
	}
	//For loop that adds i to each L2 node
	for (int i = 50; i < 100; i++)
	{
		//Pushes i into the L2 list.
		L2.Push(i);
	}

	//cout << L1 << endl;
	//Prints the Tail data node for L1 and L2, resp.
	L1.PrintTail();
	L2.PrintTail();

	//Adds data from L1 and L2 (in order) to a new list (L3).
	List L3 = L1 + L2;
	//Prints the entire L3 list to the screen.
	cout << L3 << endl;

	//Prints out the data indexed at 5 in list L3.
	cout << L3[5] << endl;
	return 0;		//END PROGRAM
}
