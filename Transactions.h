#pragma once
#include <iostream>
#include <string>

using namespace std;

//Transactions Class
class Transactions
{
public:
	//Constructors
	Transactions();
	Transactions(string t, double a);

	string transactionType; //Type of transaction, deposit or withdrawal.
	double amount; //The amount transacted.
};
