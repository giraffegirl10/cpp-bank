/* Heather Schoonmaker - CSCE 1040.315 - 4/15/2024 -> This is the implementation of the accounts class */
#include "Account.h"

//default constructor
Account::Account() {
    customerName = ' ';
	balance = 0.0f;
	accountNumber = NEXT_ACCOUNT_NUMBER++;

}

// Constructor
Account::Account(string name, float initialBalance) {
    customerName = name;
    balance = initialBalance;
    accountNumber = NEXT_ACCOUNT_NUMBER++;
}

// accessor for accountNumber
int Account::GetAccountNumber() const {
    return accountNumber;
}

//mutator for accountNumber
void Account::SetAccountNumber(int newAccountNumber){
    accountNumber = newAccountNumber;
}

// accessor for customer name
string Account::GetCustomerName() const {
    return customerName;
}

// mutator for customer name
void Account:: SetCustomerName(string name) {
    customerName = name;
}

// accessor for balance
float Account::GetBalance() const {
    return balance;
}

//mutator for balance
void Account::SetBalance(float newBalance){
    balance = newBalance;
}
    
// deposit amount into account
void Account::Deposit(float amount) {
    balance += amount;
}
    
// withdraw amount from balance (true is success, false is fail)
bool Account::Withdraw(float amount) {
    // if requested amount exceeds balance, return false
    if (amount > balance) {
        return false;
    }
        
    // otherwise we withdraw amount and return true
    balance -= amount;
    return true;
}



