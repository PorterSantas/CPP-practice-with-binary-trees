#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using namespace std;

class Payroll
{
public:
	Payroll();
	Payroll(int empNum, string first, string last, int depNum, double rate, double hours, double pay);
	void readPayroll();
	void printPayroll();
	double payAmountCalc();
	void setDepNum(int D)
	{
		departmentNumber = D;

	}
	void setEmpNum(int E)
	{
		employeeNumber = E;
	}
	void setPayRate(double PR)
	{
		payRate = PR;
	}
	void setHoursWorked(double H)
	{
		hoursWorked = H;
	}
    friend ostream& operator<< (ostream& streamObj, const Payroll& Obj)
	{
		streamObj << "Employee Number: " << Obj.employeeNumber << endl;
		streamObj << "First Name: " << Obj.firstName << endl;
		streamObj << "Last Name: " << Obj.lastName << endl;
		streamObj << "Department Number: " << Obj.departmentNumber << endl;
		streamObj << "Pay Rate: " << Obj.payRate << endl;
		streamObj << "Hours Worked: " << Obj.hoursWorked << endl;
		streamObj << "Pay Amount: " << Obj.payAmount << endl;

		return streamObj;
	}
	
	bool operator== (const Payroll& obj) const
	{
		if (employeeNumber == obj.employeeNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend bool operator< (const Payroll& obj, const Payroll obj2)
	{
		if (obj.employeeNumber < obj2.employeeNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend bool operator> (const Payroll& Obj, const Payroll Obj2)
	{
		if (Obj.employeeNumber > Obj2.employeeNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int employeeNumber;
	string firstName;
	string lastName;
	int departmentNumber;
	double payRate;
	double hoursWorked;
	double payAmount;
};

Payroll::Payroll()
{
	employeeNumber = 100000;
	firstName = "John";
	lastName = "Doe";
	departmentNumber = 0;
	payRate = 00.00;
	hoursWorked = 0.0;
	payAmount = 00.00;
}
Payroll::Payroll(int empNum, string first, string last, int depNum, double rate, double hours, double pay)
{
	employeeNumber = empNum;
	firstName = first;
	lastName = last;
	departmentNumber = depNum;
	payRate = rate;
	hoursWorked = hours;
	payAmount = pay;
}
void Payroll::readPayroll()
{
	int employee_number, department_number;
	double R, H;
	string first, last;

	cout << "What is this person's employee number? " << endl;
	cin >> employee_number;

	employeeNumber = employee_number;
	

	cout << "What is their first name? " << endl;
	cin >> first;

	firstName = first;

	cout << "What is their last name? " << endl;
	cin >> last;

	lastName = last;

	cout << "What is their department number? " << endl;
	cin >> department_number;

	departmentNumber = department_number;

	cout << "What is this person's pay rate? " << endl;
	cin >> R;

	payRate = R;

	cout << "How many hours has this person worked? " << endl;
	cin >> H;

	hoursWorked = H;

	payAmount = payAmountCalc();
}

void Payroll::printPayroll()
{
	cout << employeeNumber << endl;
	cout << firstName << endl;
	cout << lastName << endl;
	cout << departmentNumber << endl;
	cout << payRate << endl;
	cout << hoursWorked << endl;
	cout << payAmount << endl;
}

double Payroll::payAmountCalc()
{
	return (hoursWorked * payRate);
}