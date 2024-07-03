/* Heather Schoonmaker - CSCE 1040.315 - 4/15/2024 -> This is the header file for Account.cpp */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string customerName;
    float balance;

    // static variable to hold the next available account number
    static int NEXT_ACCOUNT_NUMBER;

public:
    
    //default constructor
    Account();
    
    // Constructor
    Account(string name, float initialBalance);

    // accesor for accountNumber
    int GetAccountNumber() const;

    //mutator for Account number

    void SetAccountNumber(int newAccountNumber);

    // accessor for customer name
    string GetCustomerName() const;

    // mutator for customer name
    void SetCustomerName(string name);

    // accessor for balance
    float GetBalance() const;
    
    //mutator for balance
    void SetBalance(float newBalance);

    // deposit amount into account
    void Deposit(float amount);
    
    // withdraw amount from balance (true is success, false is fail)
    bool Withdraw(float amount);
};

#endif

