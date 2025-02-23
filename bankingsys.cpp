#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
public:
    string accountNumber;
    double balance;
    
    Account(string accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }
    
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
    }
    
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: $" << amount << " | Remaining Balance: $" << balance << endl;
        return true;
    }
};

class Customer {
public:
    string name;
    Account account;
    
    Customer(string custName, string accNum, double initialDeposit) : account(accNum, initialDeposit) {
        name = custName;
    }
    
    void showDetails() {
        cout << "Customer: " << name << " | Account: " << account.accountNumber << " | Balance: $" << account.balance << endl;
    }
};

int main() {
    string name, accNum;
    double initialDeposit;
    
    cout << "Welcome to the Banking System!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Initial Deposit: ";
    cin >> initialDeposit;
    
    Customer customer(name, accNum, initialDeposit);
    
    int choice;
    do {
        cout << "\nBanking Menu:\n1. Deposit\n2. Withdraw\n3. Show Account Details\n4. Exit\nChoose an option: ";
        cin >> choice;
        
        if (choice == 1) {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            customer.account.deposit(amount);
        }
        else if (choice == 2) {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            customer.account.withdraw(amount);
        }
        else if (choice == 3) {
            customer.showDetails();
        }
        else if (choice != 4) {
            cout << "Invalid option. Try again." << endl;
        }
    } while (choice != 4);
    
    cout << "Thank you for using our banking system!" << endl;
    return 0;
}
