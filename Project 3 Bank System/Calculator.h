#include<iostream>
using namespace std;

template <typename T > class Calculator {

private:
	T Number1;
	T Number2;

public:
	Calculator(T n1, T n2)
	{
		Number1 = n1;
		Number2 = n2;
	}

	void PrintResults()
	{
		cout << "Numbers: " << Number1 << " and " << Number2 << ": " << endl;
		cout << Number1 << " + " << Number2 << " = " << Add() << endl;
		cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;
		cout << Number1 << " * " << Number2 << " = " << Multiply() << endl;
		cout << Number1 << " / " << Number2 << " = " << Divide() << endl;

	}

	T Add()
	{
		return Number1 + Number2;
	}
	
	T Subtract()
	{
		return Number1 - Number2;
	}

	T Multiply()
	{
		return Number1 * Number2;
	}

	T Divide()
	{
		return Number1 / Number2;
	}

};
