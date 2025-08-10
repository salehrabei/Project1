#include <iostream>
#include <string>
#include <vector>


using namespace std;

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


class Client {
private:
    int id;
    string name;
    string password;
    double balance;

public:
    Client() {
        this->id = 0;
        this->balance = 0;
    }
    Client(int id, string name, string password, double balance) {

        this->id = id;
        this->name = name;
        this->password = password;
        this->balance = balance;
    }

    int getId() {
        return id;
    }
    string getName() {
        return   this->name;
    }
    string getPassword() {
        return this->password;
    }
    double getBalance() {
        return this->balance;
    }


    void setId(int newId) {
        id = newId;
    }
    void setName(const string& newName) {
        if (Validation::isNameValid(newName)) {
            name = newName;
        }
        else {
            cout << "Error: Invalid name. Must be 5-20 alphabetic characters." << endl;
        }
    }

    void setPassword(const  string& newPassword) {
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
        cout << "Your current balance is: " << balance << endl;
    }

    void Display() {
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->name << endl;
        cout << "Password: " << this->password << endl;
        cout << "Balance: " << this->balance << endl;
    }
};

class Employee
{
private:
    int id;
    string name;
    string password;
    double salary;
public:
    Employee()
    {
        this->id = 0;
        this->salary = 0;
    }
    Employee(int id, string name, string password, double salary)
    {
        this->id = id;
        this->name = name;
        this->password = password;
        this->salary = salary;
    }
    void setName(const string& newName) {
        if (Validation::isNameValid(newName)) {
            name = newName;
        }
        else {
            cout << " Invalid name, Must be 5-20 alphabetic characters." << endl;
        }
    }
    void setPassword(const string& newPassword) {
        if (Validation::isPasswordValid(newPassword)) {
            password = newPassword;
        }
        else {
            cout << " Invalid password, Must be 8-20 characters long." << endl;
        }
    }
    void setId(int newId) {
        id = newId;
    }
    void setSalary(double newSalary) {
        if (Validation::isSalaryValid(newSalary)) {
            salary = newSalary;
        }
        else {
            cout << " Minimum salary is 5000" << endl;
            salary = 5000;
        }
    }
    string getName()
    {
        return this->name;
    }
    string getPassword()
    {
        return this->password;
    }
    int getId()
    {
        return this->id;
    }
    double getSalary()
    {
        return this->salary;
    }
    void Display()
    {
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->id << endl;
        cout << "Password: " << this->password << endl;
        cout << "Salary: " << this->salary << endl;
    }
};

class Admin
{
private:
    int id;
    string name;
    string password;
    double salary;
public:
    Admin()
    {
        this->id = 0;
        this->salary = 0;
    }
    Admin(int id, string name, string password, double salary)
    {
        this->id = id;
        this->name = name;
        this->password = password;
        this->salary = salary;
    }
    void setName(string& newName) {
        if (Validation::isNameValid(newName)) {
            name = newName;
        }
        else {
            cout << " Invalid name, Must be 5-20 alphabetic characters." << endl;
        }
    }

    void setPassword(string& newPassword) {
        if (Validation::isPasswordValid(newPassword)) {
            password = newPassword;
        }
        else {
            cout << " Invalid password, Must be 8-20 characters long." << endl;
        }
    }

    void setId(int newId) {
        id = newId;
    }

    void setSalary(double newSalary) {
        if (Validation::isSalaryValid(newSalary)) {
            salary = newSalary;
        }
        else {
            cout << " Minimum salary is 5000" << endl;
            salary = 5000;
        }
    }

    string getName()
    {
        return this->name;
    }
    string getPassword()
    {
        return this->password;
    }
    int getId()
    {
        return this->id;
    }
    double getSalary()
    {
        return this->salary;
    }
    void Display()
    {
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->id << endl;
        cout << "Password: " << this->password << endl;
        cout << "Salary: " << this->salary << endl;
    }
};
int main() 
{
    //Client

   Client client1(101, "Saleh Rabei ", "@Passsword_123!", 4000);
    cout << "Client 1 Info:" << endl;
    client1.Display();

    Client client2(102, "Sama Maged", "@cueps123@", 8000);
    cout << "\nClient 2 Info:" << endl;
    client1.Display();

    cout << "=======================================================================\n" << endl;

    cout << "Client 1 deposits 500" << endl;
    client1.deposit(500.0);
    client1.checkBalance();
    cout << "\n" << endl;

    cout << "Client 1 withdraws 200" << endl;
    client1.withdraw(200.0);
    client1.checkBalance();
    cout << "\n" << endl;

    cout << "Client 1 transfers to Client 2" << endl;
    client1.transferTo(1000.0, client2);
    cout << "Client 1 Balance: " << client1.getBalance() << endl;
    cout << "Client 2 Balance: " << client2.getBalance() << endl;
    cout << "========================================================================" << endl;


    // Employee
    Employee emp1(201, "Mostafa", "moS1548", 6000);
    emp1.Display();
    cout << "=========================================================================" << endl;

    //  Admin change salary 
    Admin  admin1(301, "Abeer", "alP785", 12000.0);
    admin1.Display();
    cout << "\n\n" << endl;

    cout << "New Salary  " << endl;
    admin1.setSalary(15000.0);
    admin1.Display();
    

   
}

