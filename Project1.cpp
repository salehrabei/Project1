#include <iostream>
#include <string>
#include <vector>


using namespace std;



class Client {
private:
    int id;
    string name;
    string password;
    double balance;

public:
    Client() {
        id = 0;
        balance= 0;
    }
    Client(int id, string name, string password, double balance) {

        id = id; 
        name = name;
        password = password;
       balance= balance;
    }
  
    int getId(){ 
        return id;
    }
    string getName()  {
        return name;
    }
    string getPassword()  {
        return password;
    }
    double getBalance()  { 
        return balance; 
    }


    void setId(int newId) { 
        id = newId;
    }
    void setName( string& newName) { 
        if (Validation::isNameValid(newName)) {
            name = newName;
        }
        else {
            cout << "Error: Invalid name. Must be 5-20 alphabetic characters." << endl;
        }
    }

    void setPassword( string& newPassword) { 
        if (Validation::isPasswordValid(newPassword)) {
            password = newPassword;
        }
        else {
            cout << "Error: Invalid password. Must be 8-20 characters long." << endl;
        }
    }

    void setBalance(double newBalance) { 
        if (Validation::isBalanceValid(newBalance)) {
            balance = newBalance;
        }
        else {
            cout << " Minimum balance is 150" << endl;
            balance = 1500;
        }
    }

    void deposit(double amount) { 
        if (amount > 0) {
            balance += amount;
        }
        else {
            cout << "Deposit  must be positive" << endl;
        }
    }

    void withdraw(double amount) { 
        if (amount > 0 && balance >= amount) {
            balance -= amount;
        }
        else {
            cout << " balance or invalid " << endl;
        }
    }

    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            recipient.balance += amount;
        }
        else {
            cout << "Transfer failed.  balance or invalid ." << endl;
        }
    }

    void checkBalance() { 
        cout << "Your current balance is: "  << balance << endl;
    }

    void Display() { 
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Balance: " << balance << endl;
    }
};



//  class with static validation methods
// (The Validation class is the same as in previous versions)
class Validation {
public:
    static bool isAlphabetic(const string& str) {
        for (char c : str) {
            if (!isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    static bool isNameValid(const string& name) {
        // The name must be alphabetic chars and min size 5 and max size 20
        return isAlphabetic(name) && name.length() >= 5 && name.length() <= 20;
    }

    static bool isPasswordValid(const string& password) {
        // Password must be with min size 8 and max size 20
        return password.length() >= 8 && password.length() <= 20;
    }

    static bool isBalanceValid(double balance) {
        
        return balance >= 1500;
    }

    static bool isSalaryValid(double salary) {
       
        return salary >= 5000;
    }
};
