#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNum, string accHolder, double initialBalance)
    {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    virtual void displayAccountInfo() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Balance: " << balance << endl;
    }

    virtual double calculateInterest() const
    {
        return 0.0;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string accHolder, double initialBalance, double rate)
        : BankAccount(accNum, accHolder, initialBalance)
    {
        interestRate = rate;
    }

    double calculateInterest() const override
    {
        return balance * interestRate / 100;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string accHolder, double initialBalance, double limit)
        : BankAccount(accNum, accHolder, initialBalance)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit." << endl;
        }
    }

    void checkOverdraft(double amount)
    {
        if (amount > balance + overdraftLimit)
        {
            cout << "Withdrawal exceeds overdraft limit." << endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositAccount(string accNum, string accHolder, double initialBalance, int months)
        : BankAccount(accNum, accHolder, initialBalance)
    {
        term = months;
    }

    double calculateInterest() const override
    {
        double interestRate = 5.0;
        return balance * interestRate * term / (12 * 100);
    }
};

int main()
{
    string accNum, accHolder;
    double initialBalance, interestRate, overdraftLimit;
    int accountType, term;

    cout << "Select Account Type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Checking Account" << endl;
    cout << "3. Fixed Deposit Account" << endl;
    cout << "Enter your choice: ";
    cin >> accountType;

    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin >> accHolder;
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    BankAccount *account;

    switch (accountType)
    {
    case 1:
    {
        cout << "Enter Interest Rate: ";
        cin >> interestRate;
        account = new SavingsAccount(accNum, accHolder, initialBalance, interestRate);
        break;
    }
    case 2:
    {
        cout << "Enter Overdraft Limit: ";
        cin >> overdraftLimit;
        account = new CheckingAccount(accNum, accHolder, initialBalance, overdraftLimit);
        break;
    }
    case 3:
    {
        cout << "Enter Term (in months): ";
        cin >> term;
        account = new FixedDepositAccount(accNum, accHolder, initialBalance, term);
        break;
    }
    default:
        cout << "Invalid Account Type." << endl;
        return 1;
    }

    account->displayAccountInfo();
    cout << "Interest earned: " << account->calculateInterest() << endl;

    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    account->deposit(amount);

    cout << "Enter amount to withdraw: ";
    cin >> amount;
    account->withdraw(amount);

    if (accountType == 2)
    {
        static_cast<CheckingAccount *>(account)->checkOverdraft(amount);
    }

    cout << "Updated Balance: " << account->getBalance() << endl;

    delete account;

    return 0;
}