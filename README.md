# cpp-bank

 A program that will allow the user to create accounts, withdraw money, and view accounts. 

### Sample Output

```
1. Open new account
2. Deposit into account
3. Withdraw from account
4. Fast transfer $40 into account
5. Print a list of all accounts
6. End Transaction (Exit)
```
## Main

#### Open Account
Prompts user for account information and adds it to a list of bank accounts.

```cpp
  void OpenAccount() 
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `name` | `string` |  The name of the customer |
| `initalBalance` | `float` |  The initial Balance |

#### Deposit
Tries to deposit an amount into an account if it exists.
```cpp
  void Deposit()
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `depositAmount` | `float` |  The amount to deposit into account |
| `acountNumber` | `int` |  The account number|

#### Withdraw
Tries to withdraw an amount from an account if it exists and has enough funds.
```cpp
  void Withdraw() 
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `withdrawalAmount`      | `float` | The amount to be withdrawn |

#### Fast Transfer
Quickly transfers $40 between accounts if they exist and the source account has the funds.
```cpp
  void FastTransfer()
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `source`      | `int` | The account to withdraw money from|
| `destination`      | `int` | The account to deposit money into|

#### Print Accounts
Prints list of accounts with account information.
```cpp
  void PrintAccounts()
```


#### Exit
Exits the program.
```cpp
int Exit()
```

## Account

#### Constructor

```cpp
  Account::Account(string name, float initialBalance)
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `name` | `string` |  The name of the customer |
| `initalBalance` | `float` |  The initial Balance |

#### Withdraw

```cpp
  bool Account::Withdraw(float amount)
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `amount` | `float` |  The amount to withdraw |

#### Deposit

```cpp
  void Account::Deposit(float amount)
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `amount`      | `float` | The amount to deposit |

#### Set Balance

```cpp
  void Account::SetBalance(float newBalance)
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `newBalance`      | `float` | The amount to set the balance to |

#### Set Customer Name

```cpp
  void Account:: SetCustomerName(string name)
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `name`      | `string` | The name of the customer|

#### Set Account Number

```cpp
 void Account::SetAccountNumber(int newAccountNumber)
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `newAccountNumber`      | `int` | The new account number |

#### Get balance

```cpp
  float Account::GetBalance() const 
```

#### Get Customer Name

```cpp
  string Account::GetCustomerName() const  
```
#### Get Account Number

```cpp
  int Account::GetAccountNumber() const 
```





