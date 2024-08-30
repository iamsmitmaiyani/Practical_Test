#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::string ownerName;

public:
    // Constructor
    BankAccount(const std::string& accNum, const std::string& owner, double initialBalance) 
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}

    // Method to credit (deposit) money to the account
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    // Method to debit (withdraw) money from the account
    void debit(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                std::cout << "Withdrew: $" << amount << std::endl;
            } else {
                std::cout << "Insufficient funds." << std::endl;
            }
        } else {
            std::cout << "Invalid withdrawal amount." << std::endl;
        }
    }

    // Method to display account details and balance
    void displayBalance() const {
        std::cout << "Account Number: " << accountNumber 
                  << "\nOwner Name: " << ownerName 
                  << "\nBalance: $" << balance 
                  << std::endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount myAccount("123456789", "John Doe", 1000.00);

    // Display initial balance
    myAccount.displayBalance();

    // Credit and debit operations
    myAccount.credit(500.00);  // Deposit $500
    myAccount.debit(200.00);   // Withdraw $200

    // Display balance after transactions
    myAccount.displayBalance();

    // Attempting invalid operations
    myAccount.credit(-50.00);  // Invalid deposit
    myAccount.debit(2000.00);  // Insufficient funds

    // Display balance after invalid operations
    myAccount.displayBalance();

    return 0;
}
