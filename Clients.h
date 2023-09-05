#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Transactions.h"

using namespace std;

//Client Class
class Client : public Transactions //Shares with "Transactions.h"
{
public:
    //Default Constructor
    Client();
    //Constructor
    Client(string ln, string fn, double b, string t, double a);
    //Utility Functons
    void readClientInfo();
    void displayClientInfo();
    void cstack();
    void displayNext();
    void serveClients();

    fstream inputFile;
    int recordCount;
    int stackCount;
    string firstName, lastName; //Client Name.
    double balance; //Client balance.
    Transactions clientTransaction; //Client transaction type and amount.
    stack<string> clients; //Client name stack (First Name)
    stack<double> bAmount; //Balance Stack
    stack<double> tAmount; //Transaction Stack
    stack<string> tType; //Transaction type stack
};
