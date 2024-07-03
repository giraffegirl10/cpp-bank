
/* Heather Schoonmaker - CSCE 1040.315 - 4/15/2024 -> A program that will allow the user to create accounts, withdraw money, and view accounts. */
#include "Project3.h"

// container for our accounts
static vector<Account> accounts;

// initialize our static account number to 1000
int Account::NEXT_ACCOUNT_NUMBER = 1000;

// helper to find an account by user inputted number
Account* FindAccountByNumber() {
    int accountNumber;
    bool found = false;
    
    // prompt user for account number
    cout << "Enter account number: ";
    cin >> accountNumber;
    
    // loop over all accounts and see if we find a matching account
    for (size_t i = 0; i < accounts.size(); i++) {
        Account& account = accounts.at(i);
        
        // check to see if this account is the one we are looking for
        if (account.GetAccountNumber() == accountNumber) {
            found = true;
            
            // return the found account pointer
            return &account;
        }
    }
    
    // if we can't find the account, show an error
    if (!found) {
        cout << "Account number " << accountNumber << " not found.\n\n";
    }
    
    // return nullptr to show we can't find the account
    return nullptr;
}

void OpenAccount() {
    string ownerName;
    float startingBalance;

    // ask user for the customer name
    cout << "Enter customer account name: ";
    cin.ignore();
    // gets the entire line and assign to ownerName
    getline(cin, ownerName);

    // ask user for the deposit amount
    cout << "Enter initial deposit amount: $";
    cin >> startingBalance;

    // create a new account with user inputs and add it into our vector
    Account account(ownerName, startingBalance);
    accounts.push_back(account);

    // show user the newly created account
    cout << "Account opened: " << account.GetAccountNumber() << " --- " << account.GetCustomerName() << ": " << "$" << fixed << setprecision(2) << account.GetBalance() << "\n\n";
}

void Deposit() {
    float depositAmount = 0.0f;

    // find account by number
    Account* account = FindAccountByNumber();
    
    // if we found account, continue to deposit
    if (account != nullptr) {
        // ask user for deposit amount
        cout << "Enter deposit amount: $";
        cin >> depositAmount;
        
        // deposit amount user entered and show new balance
        account->Deposit(depositAmount);
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << account->GetBalance() << "\n\n";
    }
}

void Withdraw() {
    float withdrawalAmount = 0.0f;
    string accountName;

    // find account by number
    Account* account = FindAccountByNumber();
    
    // if we found account, continue to withdraw
    if (account != nullptr) {
        // ask user for account name
        cout << "Enter account name for security purpose: ";
        cin.ignore();
        getline(cin, accountName);

        if (account->GetCustomerName() != accountName) {
            cout << "Error: Account number and name do not match or account not found. Access denied.\n\n";
            return;
        }

        // ask user for withdrawal amount
        cout << "Enter withdrawal amount: $";
        cin >> withdrawalAmount;
        
        // attempt to withdraw the amount entered
        bool success = account->Withdraw(withdrawalAmount);

        // if we were allowed to withdraw, show new balance, otherwise show error
        if (success) {
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << account->GetBalance() << "\n\n";
        } else {
            cout << "Insufficient funds or withdrawal failed.\n\n";
        }
    }
}

void FastTransfer() {
    int source, destination;
    Account* sourceAccount = nullptr;
    Account* destinationAccount = nullptr;

    cout << "$40 Fast Transfer: source -> destination\n";
    cout << "Enter source account number: ";
    cin >> source;
    cout << "\nEnter destination account number: ";
    cin >> destination;

    for (size_t i = 0; i < accounts.size(); i++) {
        Account& account = accounts.at(i);

        // check to see if this account is the one we are looking for
        if (account.GetAccountNumber() == source) {
            sourceAccount = &account;
        }
        else if (account.GetAccountNumber() == destination) {
            destinationAccount = &account;
        }
    }

    if (sourceAccount == nullptr || destinationAccount == nullptr) {
        cout << "Error: Source or destination account number not found. Operation failed.\n\n";
        return;
    }

    bool success = sourceAccount->Withdraw(40);
    if (!success) {
        cout << "Insufficient funds or withdrawal failed.\n\n";
    }

    destinationAccount->Deposit(40);
    cout << "$40 Fast Transfer processed: " << source << " -> " << destination << "\n\n";
}

void PrintAccounts() {
    size_t accountsSize = accounts.size();

    // show error if there are no accounts
    if (accountsSize == 0) {
        cout << "There are no accounts.\n\n";
    }

    // show a list of all of the accounts in a table
    cout << "ACCOUNT NUMBER | ACCOUNT OWNER | BALANCE\n";
    cout << "----------------------------------------\n";
    
    // loop over all accounts and show the information about that account
    for (size_t i = 0; i < accountsSize; i++) {
        Account& account = accounts.at(i);
        cout << account.GetAccountNumber() << "           | " << account.GetCustomerName() << "   | $" << fixed << setprecision(2) << account.GetBalance() << endl;
    }
}

int Exit() {
    cout << "Thank you for your business!\n\n";
    return 0;
}

int main() {

    cout << "+------------------------------------------------+\n";
    cout << "| Computer Science and Engineering               |\n";
    cout << "| CSCE 1040 - Computer Programming II            |\n";
    cout << "| Heather Schoonmaker hls0156 hls0156@my.unt.edu |\n";
    cout << "+------------------------------------------------+\n";
    int input = 0;
    
    // Continue until user wants to exit
    while (input != 6) {
        cout << "1. Open new account\n";
        cout << "2. Deposit into account\n";
        cout << "3. Withdraw from account\n";
        cout << "4. Fast transfer $40 into account\n";
        cout << "5. Print a list of all accounts\n";
        cout << "6. End Transaction (Exit)\n";
        cout << "> ";
        cin >> input;
        
        switch (input) {
            // Open a new account
            case 1: {
                OpenAccount();
                break;
            }
            // Deposit into account
            case 2: {
                Deposit();
                break;
            }
            // Withdraw from account
            case 3: {
                Withdraw();
                break;
            }
            // Fast transfer
            case 4: {
                FastTransfer();
                break;
            }
            // Print all accounts
            case 5: {
                PrintAccounts();
                break;
            }
            // Exit program
            case 6: {
                Exit();
		        break;
            }
	        default: {
		        cout << "Invalid input, please enter a number between 1 and 5\n\n";
		        break;
	        }
        }
    }
}

