#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    string accountType;
    float accountBalance;

public:
    BankAccount(const string& number, const string& holderName, const string& type, float balance)
        : accountNumber(number), accountHolderName(holderName), accountType(type), accountBalance(balance) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    string getAccountType() const {
        return accountType;
    }

    float getAccountBalance() const {
        return accountBalance;
    }

    float Deposit(float amount) {
        accountBalance += amount;
        return accountBalance;
    }

    float Withdraw(float amount) {
        accountBalance -= amount;
        return accountBalance;
    }

    void operator== (const BankAccount& other) {
        if (accountNumber == other.getAccountNumber()) {
            cout << "It's the same account." << endl;
        } else {
            cout << "The account numbers are different." << endl;
        }
    }

    virtual float interestRate() {
        return 0.0f;
    }
};

class SavingsAccount : public BankAccount {
public:
    float interestRate() override {
        cout << "The interest rate for Savings Account is 3%." << endl;
        return 3.0f;
    }
};

class CheckingAccount : public BankAccount {
public:
    float interestRate() override {
        cout << "The interest rate for Checking Account is 1%." << endl;
        return 1.0f;
    }
};

int main() {
    float x;
    BankAccount acc1("123456", "John Doe", "Savings", 500.0);
    BankAccount acc2("789012", "Jane Smith", "Checking", 700.0);

    acc1 == acc2; 

    return 0;
}
