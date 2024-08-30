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
        } else {
            std::cerr << "Invalid deposit amount." << std::endl;
        }
    }

    // Method to debit (withdraw) money from the account
    void debit(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
            } else {
                std::cerr << "Insufficient funds." << std::endl;
            }
        } else {
            std::cerr << "Invalid withdrawal amount." << std::endl;
        }
    }

    // Method to display account details
    void displayBalance() const {
        std::cout << "Account Number: " << accountNumber 
                  << "\nOwner Name: " << ownerName 
                  << "\nBalance: $" << balance 
                  << std::endl;
    }

    // Overload the << operator to display account details
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& account);
};

// Overload the << operator to display account details
std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Account Number: " << account.accountNumber 
       << "\nOwner Name: " << account.ownerName 
       << "\nBalance: $" << account.balance;
    return os;
}

int main() {
    // Create two BankAccount objects
    BankAccount account1("123456789", "John Doe", 1000.00);
    BankAccount account2("987654321", "Jane Smith", 1500.00);

    // Display account details using the overloaded << operator
    std::cout << "Account 1 Details:\n" << account1 << std::endl;
    std::cout << "\nAccount 2 Details:\n" << account2 << std::endl;

    return 0;
}
