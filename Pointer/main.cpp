#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int MAX_NUM = 64;
const int MAX_SIZE = 8;

void Show(const string ARGS, const int *VALUE, const int SIZE);
void SquareByAddress(int *ptr);
void SwapListOne(int *list1, int *list2);
void SwapListTwo(int *&list1, int *&list2);
void Segment();

int main()
{
	// declaring pointer
	// typeName * variableName; //asterisk
	int *p1;      // declaration of a pointer, called p1 
	int *p2, *p3, *p4; // declaration of three pointer
	int *p5, n1, n2; // p4 is pointer, n1 and n2 are int
	int iArr1[MAX_SIZE];
	int iArr2[MAX_SIZE];

	for(int i = 0; i < MAX_SIZE; i++)
	{
		iArr1[i] = rand() % MAX_NUM;
		iArr2[i] = rand() % MAX_NUM;
	}
	n1 = rand() % MAX_NUM;
	n2 = 4;

	// For safty and security purpose. Always initialize pointer to something.(NULL)  
	p3 = NULL;
	p4 = NULL;
	p5 = NULL;

	Show("n1", &n1, 1);
	Show("n2", &n2, 1);
	Show("iArr1", iArr1, MAX_SIZE);
	Show("iArr2", iArr2, MAX_SIZE);
	Segment();

	p1 = &n1; // p1 is pointing to the address of n1
	p2 = &n1; // p2 is pointing to the address of n1
	cout << "p1 is " << p1 << endl; // address p1 is pointing at
	cout << "p2 is " << p2 << endl; // address p2 is pointing at
	cout << "*p1 is " << *p1 << endl; // dereferenced pointer p1 and get target value
	Show("p2", p2, 1);

	cout << "*(&n1) is " << *(&n1) << endl;
	cout << "&n1 is " << &n1 << endl; 
	cout << "&(*p1) is " << &(*p1) << endl; 

	*p1 = 123;
	Show("After (*p1 = 123) p1", p1, 1);
	Show("After (*p1 = 123) p2", p2, 1);
	Show("After (*p1 = 123) n1", &n1, 1);
	Segment();

	cout << "p3 is " << p3 << endl; 
	p3 = &n2;
	cout << "At t1, p3 is " << p3 << endl; 
	SquareByAddress(p3);
	Show("After (SquareByAddress(p3)) p3", p3, 1);
	Show("After (SquareByAddress(p3)) n2", &n2, 1);
	cout << "At t2, p3 is " << p3 << endl; 

	SquareByAddress(&n2);
	Show("After (SquareByAddress(&n2)) p3", p3, 1);
	Show("After (SquareByAddress(&n2)) n2", &n2, 1);
	Segment();

	p2 = iArr1;
	Show("p2", p2, MAX_SIZE);
	cout << "iArr1[3] = " << iArr1[3] << endl;
	cout << "&(iArr1[3]) = " << &(iArr1[3]) << endl;
	cout << "p2 + 3 = " << p2 + 3 << endl;
	cout << "*(p2 + 3) = " << *(p2 + 3) << endl;
	cout << "p2[3] = " << p2[3] << endl;
	Segment();

	p4 = iArr1;
	p5 = iArr2;
	Show("p4", p4, MAX_SIZE);
	Show("p5", p5, MAX_SIZE);

	SwapListOne(p4, p5);
	cout << "(main) After SwapListOne " << endl;
	Show("p4", p4, MAX_SIZE);
	Show("p5", p5, MAX_SIZE);

	SwapListTwo(p4, p5);
	cout << "(main) After SwapListTwo " << endl;
	Show("p4", p4, MAX_SIZE);
	Show("p5", p5, MAX_SIZE);	
	Segment();

	return 0;
}

void Show(const string ARGS, const int *VALUE, const int SIZE)
{
	cout << ARGS << " = ";
	for(int i = 0; i < SIZE; i++)
	{
		cout << *(VALUE + i) << " "; // means same as VALUE[i]
	}
	cout << endl;
}

// Note that this function doesn't return anything.  void function.
void SquareByAddress(int *ptr)
{  
	*ptr = (*ptr) * (*ptr);  		// modifying the target, *ptr
} 

void SwapListOne(int *list1, int *list2)
{
	int *tmpPtr;
	tmpPtr = list1;
	cout << "===(SwapListOne)===" << endl;
	Show("list1", list1, MAX_SIZE);
	Show("list2", list2, MAX_SIZE);
	list1 = list2;
	list2 = tmpPtr;	
	cout << "After Swap" << endl;
	Show("list1", list1, MAX_SIZE);
	Show("list2", list2, MAX_SIZE);
	cout << "===================" << endl;
}

void SwapListTwo(int *&list1, int *&list2)
{
	int *tmpPtr;
	tmpPtr = list1;
	cout << "===(SwapListTwo)===" << endl;
	Show("list1", list1, MAX_SIZE);
	Show("list2", list2, MAX_SIZE);
	list1 = list2;
	list2 = tmpPtr;	
	cout << "After Swap" << endl;
	Show("list1", list1, MAX_SIZE);
	Show("list2", list2, MAX_SIZE);
	cout << "===================" << endl;
}

void Segment()
{
	for(int i = 0; i < 40; i++)
		cout << "-";
	cout << endl;
}


