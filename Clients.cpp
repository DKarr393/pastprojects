#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <fstream>
#include "Clients.h"
#include "Transactions.h"

using namespace std;

//Client Functions
fstream inputFile;
int recordCount;
int stackCount;
stack<string> clients; //Client name stack (First Name)
stack<double> bAmount; //Balance Stack
stack<double> tAmount; //Transaction Stack
stack<string> tType; //Transaction type stack

//Default Constructor
Client::Client()
	:clientTransaction() {
	lastName = "";
	firstName = "";
	balance = 0.00;
}

//Constructor
Client::Client(string ln, string fn, double b, string t, double a)
	:clientTransaction(t, a) {
	lastName = ln;
	firstName = fn;
	balance = b;
}

void Client::readClientInfo() {
	cout << "  #	Name				  Balance	Transaction		   Amount" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	recordCount = 0;
	stackCount = 0;
	//Opens text file "ClientInfo.txt" for project.
	inputFile.open("ClientInfo.txt");
	//Reads the first field, of the first line in the text file.
	inputFile >> lastName;
	//A while loop to read and output data from "ClientInfo.txt".
	while (!inputFile.eof())
	{
		inputFile >> firstName >> balance >> transactionType >> amount; //Reads the remaining fields.
		cstack(); //Pushes firstname, balance, transaction type, and transaction amount into stacks, all at once.
		inputFile >> lastName; //Starts reading the next line (First field).
	}
	inputFile.close(); //Closes "ClientInfo.txt".
}

//Pushes items into a stack and tracks the size.
void Client::cstack() {
	stackCount++; //Tracks items in stack by fives.
	recordCount++; //Counts total amount of records within the text file.
	clients.push(firstName); //Pushes the first name into the stack.
	bAmount.push(balance); //Pushes the balance numbers into the stack.
	tAmount.push(amount); //Pushes the transaction amount into the stack.
	tType.push(transactionType); //Pushes the transaction type into the stack.
	cout << setw(3) << right << recordCount << ".	"; //Displays the record count.
	displayClientInfo();
	if (inputFile.eof()) {		//Assumes that when the list is fully read, the last client must be printed even if the stack number is not a multiple of 5.
		displayNext();			//No matter how many items are in the text file, the program will run correctly.
		cout << "		Queue Complete!" << endl; //displays on last item of the queue.
		cout << "-----------------------------------------------------------------------------------------" << endl;
	}
	else if (stackCount == 5) { //When the stack is a multiple of 5, the next client and stack size is displayed.
		displayNext();
		cout << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		cout << "  #	Name				  Balance	Transaction		   Amount" << endl;
		cout << "-----------------------------------------------------------------------------------------" << endl;
		stackCount = 0; //Clears the stack counter.
	}
}

//Displays the next client.
void Client::displayNext() {
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "Stack size: " << recordCount << "			Next to be served: " << clients.top(); //Stack size and Client displayed.
}

//Nested into ReadClientInfo, displays information.
void Client::displayClientInfo() {
	//Uses manipulators to display decimal point values (in cents).
	cout << fixed << setprecision(2);
	cout << setw(8) << left << firstName << " " << setw(12) << left 
		<< lastName << "	$" << setw(16) << right << balance << "	" << setw(8) << left
		<< transactionType << "	$" << setw(16) << right << amount << endl;						//Setw() used for presentation.
}

void Client::serveClients() {
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << ">	Serving Clients..." << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
	int newRecordCount = recordCount; //Copies count, for output. Tracks queue number.
	string possessive = "'s New Balance:		$"; //String is declared for presentation purposes.
	for (int i = 1; i <= recordCount; i++) { //recordCount stays the same, so that any size list runs correctly.
		cout << setw(3) << right << newRecordCount << ".	"<< setw(19) << left << clients.top() + possessive;
		if (tType.top() == "Withdrawal") //Reads top of the tType stack, if Transaction Type = Withdrawal -> money is subtracted.
		{
			cout << setw(16) << right << bAmount.top() - tAmount.top() << endl; //Withdrawing money, means losing balance.
			clients.pop();														//All stacks are popped in unison, next record is read.
			bAmount.pop();
			tAmount.pop();
			tType.pop();
			newRecordCount--;													//Tracks record being transacted, decrements as last customer is served first.
		}
		else if (tType.top() == "Deposit") //Reads top of the tType stack, if Transaction Type = Deposit -> money is added.
		{
			cout << setw(16) << right << bAmount.top() + tAmount.top() << endl; //Depositing money, means gaining balance.
			clients.pop();														//All stacks are popped in unison, next record is read.
			bAmount.pop();
			tAmount.pop();
			tType.pop();
			newRecordCount--;													//Tracks record being transacted, decrements as last customer is served first.
		}
	}
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << ">	Service Complete!		-		Press 'Enter' to end program" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
}