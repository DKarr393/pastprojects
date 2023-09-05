#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <iomanip>
#include "Clients.h"
#include "Transactions.h"

using namespace std;

int main() {
	Client q; //Queue
	char answer;
	q.readClientInfo(); //Runs all needed functions.

	//Asks user if they wish to serve clients.
	cout << "\n\n>	Serve Clients?			-		Type 'Y' to serve clients" << endl;
	cin >> answer; //User inputs answer.
	cout << endl;
	if (answer == 'Y') //lower-case y is acceptable.
	{
		q.serveClients(); //Serves clients, most recent customer first.
	}
	else if (answer == 'y') //upper-case Y is acceptable.
	{
		q.serveClients(); //Serves clients, most recent customer first.
	}
	else					//Anything else is not.
	{
		cout << "Goodbye!" << endl;
		return 0;
	}

	return 0;
}