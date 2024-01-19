// Porter Santas
// Project 2
// Program that can store and manipulate the Payroll object that is stored within a binarySearchTree

#include <iostream>

#include "binarySearchTree.h"
#include "Payroll.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


using namespace std;

void PrintByDepartment(const bSearchTreeType<Payroll>& L, int department); 
void RunPayroll(const bSearchTreeType<Payroll>& L, int department);
void printMenu();

int main()
{
	int menuChoice;
	bool repeat = true;

	bSearchTreeType<Payroll> tree1;
	
	do {
		printMenu();
		cin >> menuChoice;
		if (menuChoice == 1)
		{
			Payroll dummy1;

			dummy1.readPayroll();

			tree1.insert(dummy1);
		}
		else if (menuChoice == 2)
		{
			int eNum;
			Payroll dummy;

			cout << "Please enter the employee number of the object you would like to delete from the tree " << endl;
			cin >> eNum;

			dummy.setEmpNum(eNum);

			tree1.deleteNode(dummy);
		}
		else if (menuChoice == 3)
		{
			int eNum;
			Payroll dummy;

			cout << "Please enter the employee number of the object you would like to search for in the tree " << endl;
			cin >> eNum;

			dummy.setEmpNum(eNum);

			tree1.search(dummy);
			
		}
		else if (menuChoice == 4)
		{
			//Update Payroll Data
			Payroll dummy3;
			int E_NUM;

			cout << "What is the employee number of the employee you are searching for? " << endl;
			cin >> E_NUM;

			dummy3.setEmpNum(E_NUM);
			
			tree1.search(dummy3);

			if (tree1.search(dummy3) == false)
			{
				cout << "Error: Cannot edit a non existent employee " << endl;
			}
			else
			{
				Payroll replace;

				replace.readPayroll();

				tree1.insert(replace);
			}
		}
		else if (menuChoice == 5)
		{
			int depDummy;

			cout << "Which department would you like to display the info for? " << endl;
			cin >> depDummy;

			RunPayroll(tree1, depDummy);
		}
		else if (menuChoice == 6)
		{
			if (tree1.isEmpty() == true)
			{
				cout << "Cannot access data from empty tree " << endl;
			}
			else
			{
				tree1.preorderTraversal();
			}
		}
		else if (menuChoice == 7)
		{
			int depDummy;

			cout << "Which department would you like to display the info for? " << endl;
			cin >> depDummy;

			PrintByDepartment(tree1,depDummy);
		}
		else if (menuChoice == 8)
		{
			repeat = false;
		}

	} while (repeat);


}

void PrintByDepartment(const bSearchTreeType<Payroll>& L, int department)
{
	Payroll dummy;
	
	dummy.setDepNum(department);

	for (int j = 0; j <= L.treeNodeCount(); j++)
	{
		dummy = L.Payrollin(dummy);
	}

	cout << dummy;
}

void RunPayroll(const bSearchTreeType<Payroll>& L, int department)
{
	Payroll dummy;
	double totalPay = 0.0;
	
	dummy.setDepNum(department);
	
	for (int i = 0; i <= L.treeNodeCount(); i++)
	{
			dummy = L.Payrollin(dummy);
			cout << dummy.payAmountCalc();
	}

	cout << "Payroll has been processed! " << endl;
}

void printMenu()
{
	cout << "Payroll Menu " << endl;
	cout << "======================================== " << endl;
	cout << "1. Insert a Payroll Object Into the Tree " << endl;
	cout << "2. Delete a Payroll Object From the Tree " << endl;
	cout << "3. Search for Employee Payroll Data " << endl;
	cout << "4. Update Payroll Data " << endl;
	cout << "5. Run Payroll " << endl;
	cout << "6. Print Entire Tree " << endl;
	cout << "7. Print Payroll Objects by Department Number" << endl;
	cout << "8. Exit the Program " << endl;
	cout << "--------------------------------------- " << endl;
}