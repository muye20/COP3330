#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "myint.h"

using namespace std;

#define PRINT_TABLE 0

const int LEN = 11;
const string FN = "Big_Number_Test.txt";
enum OP_TYPE {E = 0, LE, GE, L, G, NE, PRE_INC, POS_INC, ADD, MULT, SUB, DIV, MOD};
const char OPERATOR[][MOD] = {"==", "<=", ">=", "<", ">", "!=", "Pre++", "Post++", "+", "*", "-", "/", "%"}; 

template < class T >
void ReadNum(T list[], const char *f);
template < class T >
void PrintNum(T list[], const char *str);
template <typename S>
void TestRelationalOp(S list [], bool mat[][LEN], const int op);
template <typename S>
void TestArithmeticOp(S list [], S mat[][LEN], const int op);
template <typename S, typename T>
void PrintTable(S list [], T mat[][LEN], const int op);
template <typename S, typename T>
bool IsSame(S list1[], T list2[]);
template <typename S, typename T>
bool Check(S mat1[][LEN], T mat2[][LEN]);
MyInt Fibonnaci(MyInt num);
void Foo(MyInt num);

int main()
{
	MyInt a(-100);			// test negative integer 
	MyInt b("120h");		// test invalid c-string
	MyInt c(789);			// test int conversion constructor
	MyInt d("0000");		
	
	cout << a << endl;
	cout << b << endl;
	Foo(c);					// test copy constructor
	cout << c << endl;
	cout << d << endl;

	string slist[LEN];			// string array
	int ilist[LEN];				// int array
	MyInt blist[LEN];			// MyInt array 
	MyInt blist_str[LEN];		// MyInt array initialized by c-string
	MyInt blist_int[LEN];		// MyInt array initialized by int

	bool i_rel_mat[LEN][LEN];
	bool b_rel_mat[LEN][LEN];

	int i_mat[LEN][LEN];		
	MyInt b_mat[LEN][LEN];
	MyInt *test_list;

	test_list = NULL;
	ReadNum(slist, FN.c_str());  // read into string array
	ReadNum(ilist, FN.c_str());  // read into int array
	ReadNum(blist, FN.c_str());  // read into MyInt array

	for(int i = 0; i < LEN; i++)
	{
		blist_str[i] = slist[i].c_str();	// test assignment operator and c-string conversion constructor
		blist_int[i] = ilist[i];			// test assignment operator and int conversion constructor
	}

	cout << "int list and MyInt list ";
	if(IsSame(ilist, blist))
	{
		cout << "The same " << endl;
		if(test_list == NULL) 
		{
			cout << "use myint initialized by >> operator" << endl;
			test_list = blist;
		}
	}
	else
		cout << "Not the same " << endl;

	cout << "int list and MyInt(c-string) list ";
	if(IsSame(ilist, blist_str))
	{
		cout << "The same " << endl;
		if(test_list == NULL)
		{
			cout << "use myint initialized by c-string conversion constructor" << endl;
			test_list = blist_str;
		}
	}
	else
		cout << "Not the same " << endl;

	cout << "int list and MyInt(int) list ";
	if(IsSame(ilist, blist_int))
	{
		cout << "The same " << endl;
		if(test_list == NULL)
		{
			cout << "use myint initialized by int conversion constructor" << endl;
			test_list = blist_int;
		}
	}
	else
		cout << "Not the same " << endl;
		
	if(test_list == NULL)	
	{
		cout << "use myint initialized by int conversion constructor" << endl;
		test_list = blist_int;			
	}

	PrintNum(slist, "string list");					// print string array
	PrintNum(ilist, "int list");					// print int array
	PrintNum(blist, "MyInt list");					// print MyInt array
	PrintNum(blist_str, "MyInt list (str)");		// print MyInt array 
	PrintNum(blist_int, "MyInt list (int)");		// print MyInt array

	// test "==", "<=", ">=", "<", ">", "!="
	for(int i = E; i <= NE; i++)
	{
		cout << left;
		cout << setw(7) << OPERATOR[i] << "Overloading: " << "\t";
		cout << right;
		TestRelationalOp(ilist, i_rel_mat, i);
		TestRelationalOp(test_list, b_rel_mat, i);

		if(Check(i_rel_mat, b_rel_mat))
			cout << "Passed "<< endl;
		else
		{
			cout << "Failed "<< endl;
			if(!PRINT_TABLE)
			{
				PrintTable(ilist, i_rel_mat, i);
				PrintTable(test_list, b_rel_mat, i);
			}			
		}

		if(PRINT_TABLE)
		{
			cout << "int version " << endl;
			PrintTable(ilist, i_rel_mat, i);
			cout << "myint version " << endl;
			PrintTable(test_list, b_rel_mat, i);				
		}		
	}
	
	// test "Pre++", "Post++", "+", "*"
	// for extra credit 
	// for(int i = PRE_INC; i <= MOD; i++)
	for(int i = PRE_INC; i <= MULT; i++)
	{
		cout << left;
		cout << setw(7) << OPERATOR[i] << "Overloading: " << "\t";
		cout << right;
		TestArithmeticOp(ilist, i_mat, i);
		TestArithmeticOp(test_list, b_mat, i);

		if(Check(i_mat, b_mat))
			cout << "Passed "<< endl;
		else
		{
			cout << "Failed "<< endl;
			if(!PRINT_TABLE)
			{
				PrintTable(ilist, i_mat, i);
				PrintTable(test_list, b_mat, i);
			}			
		}

		if(PRINT_TABLE)
		{
			cout << "int version " << endl;
			PrintTable(ilist, i_mat, i);
			cout << "myint version " << endl;
			PrintTable(test_list, b_mat, i);				
		}		
	}

	// create Fibonacci numbers (stored as MyInts) using +
	cout << "\nAssuming that the Fibonnaci sequence begins 1,1,2,3,5,8,13..."
		<< "\n\nThe 10th Fibonnaci number   = " << Fibonnaci(10)
		<< "\n\nThe 100th Fibonnaci number  = " << Fibonnaci(100)
		<< "\n\nThe 1000th Fibonnaci number = " << Fibonnaci(1000)
		<< "\n\nThe 2000th Fibonnaci number = " << Fibonnaci(2000)
		<< "\n\nThe 20000th Fibonnaci number = " << Fibonnaci(20000)
		<< "\n\n";
		
	return 0;
}

template < class T >
void ReadNum(T list[], const char *f)
{
	ifstream fin;
	fin.open(f, ios::in);

	if(fin)
	{
		for(int i = 0; i < LEN; i++)
			fin >> list[i];	
		fin.clear();
		fin.close();
	}
	else
		cout << "Cannot Open the file " << endl;
}

template <typename S,typename T>
bool IsSame(S list1[], T list2[])
{
	int i = 0;
	bool same = true;

	while(i < LEN && same)
	{
		if(list1[i] != list2[i])
			same = false;
		i++;
	}

	return same;
}

template < class T >
void PrintNum(T list[], const char *str)
{
	int width = 8;
	cout << left;
	cout << setw(16) << str << " : ";
	for(int i = 0; i < LEN; i++)
		cout << setw(width) << list[i];
	cout << right;
	cout << endl;
}

template <typename S>
void TestArithmeticOp(S list [], S mat[][LEN], const int op)
{
	S tmp;
	for(int i = 0; i < LEN; i++)
	{
		for(int j = 0; j < LEN; j++)
		{
			switch (op)
			{	
			case PRE_INC:
				if(i == j)
				{
					tmp = list[i];
					mat[i][j] = ++tmp;
				}
				else
					mat[i][j] = 0;
				break;
			case POS_INC:
				if(i == j)
				{
					tmp = list[i];
					mat[i][j] = tmp++;
				}
				else
					mat[i][j] = 0;
				break;	
			case ADD:
				mat[i][j] = list[i] + list[j];
				break;
			case MULT:
				mat[i][j] = list[i] * list[j];
				break;				
			// case SUB:
				// mat[i][j] = list[i] - list[j];
				// if(mat[i][j] < 0) mat[i][j] = 0;
				// break;
			// case DIV:
				// if(list[j] != 0)
					// mat[i][j] = list[i] / list[j];
				// break;
			// case MOD:
				// if(list[j] != 0)
					// mat[i][j] = list[i] % list[j];
				// break;
			default:
				mat[i][j] = 0;
				break;
			}
		}
	}
}

template <typename S>
void TestRelationalOp(S list [], bool mat[][LEN], const int op)
{
	for(int i = 0; i < LEN; i++)
	{
		for(int j = 0; j < LEN; j++)
		{
			switch (op)
			{	
			case E:
				mat[i][j] = (list[i] == list[j]);
				break;
			case LE:
				mat[i][j] = (list[i] <= list[j]);
				break;
			case GE:
				mat[i][j] = (list[i] >= list[j]);
				break;
			case L:
				mat[i][j] = (list[i] < list[j]);
				break;
			case G:
				mat[i][j] = (list[i] > list[j]);
				break;
			case NE:
				mat[i][j] = (list[i] != list[j]);
				break;
			default:
				mat[i][j] = 0;
				break;
			}
		}
	}
}

template <typename S, typename T>
void PrintTable(S list [], T mat[][LEN], const int op)
{
	int i, j;
	int width = 11;
	cout << left;
	cout << setw(width) << OPERATOR[op];
	for(i = 0; i < LEN; i++)
		cout << setw(width) << list[i];
	cout << endl;

	for(i = 0; i < LEN; i++)
	{
		cout << setw(width) << list[i];
		for(j = 0; j < LEN; j++)
		{
			cout << setw(width) << mat[i][j];
		}
		cout << endl;
	}
	cout << right;
	cout << endl;
}

template <typename S, typename T>
bool Check(S mat1[][LEN], T mat2[][LEN])
{
	int i = 0;
	int j = 0;
	bool pass = true;

	while(i < LEN && pass)
	{
		j = 0;
		while(j < LEN && pass)
		{
			if(mat1[i][j] != mat2[i][j])
				pass = false;
			j++;
		}
		i++;
	}

	return pass;
}

MyInt Fibonnaci(MyInt num)
{
	MyInt n1 = 1, n2 = 1, n3;
	MyInt i = 2;
	while (i < num)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		i++;
	}
	return n2;
}

void Foo(MyInt num)
{
	cout << num << endl;
}

