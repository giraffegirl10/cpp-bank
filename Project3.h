/* Heather Schoonmaker - CSCE 1040.315 - 4/15/2024 -> This is the header file for the Project3.cpp file */
#ifndef PROJECT3_H
#define PROJECT3_H

#include <vector>
#include <string>
#include "Account.h"

// Function declarations
Account* FindAccountByNumber();
void OpenAccount();
void Deposit();
void Withdraw();
void FastTransfer();
void PrintAccounts();
int Exit();

#endif

