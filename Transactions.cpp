#include "Transactions.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Transactions functions

//Default Constructor, made so that Client functions work.
Transactions::Transactions() {
	transactionType = "";
	amount = 0.00;
}
//Constructor
Transactions::Transactions(string t, double a) {
	transactionType = t;
	amount = a;
}