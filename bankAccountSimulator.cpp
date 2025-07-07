/*
 
 TODO: Instructions 1st half:
 
 Create a BankAccount class with:
 A balance variable
 A method to make a purchase (deduct from balance)
 A method to deposit funds
 A method to print the current balance
 A method to save each transaction to a file
 
 TODO: Instructions 2nd half:
 
 Include a simple test in main() that:
 Creates a BankAccount object
 Adds an initial deposit
 Makes at least two purchases
 Prints the final balance
 Writes each action (deposit and purchase) to transactions.txt
 
 */


#include <iostream>
#include <fstream> // fstream for file input/output
#include <string>
using namespace std;

class BankAccount {
    
private:
    double balance;
    
public:
    BankAccount(){
        balance = 0.0;
    }
    
    void purchase(double amount){
        balance -= amount;
    }
    
    void deposit(double amount){
        balance += amount;
    }
    
    void showBalance(){
        cout << "\nBalance: $" << balance << endl;
    }
    
    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }
    
};

int main(){
    BankAccount* bankAccount1 =  new BankAccount();
    
    bankAccount1->deposit(1000);
    cout << "\nInitial Deposit: $1000" << endl;
    bankAccount1->saveTransaction("Deposit", 1000);
    
    bankAccount1->purchase(525.27);
    cout << "\nPurchase #1: $525.27 - McDonald's" << endl;
    bankAccount1->saveTransaction("Purchase", 525.27);
    
    bankAccount1->purchase(412.99);
    cout << "\nPurchase #2: $412.99 - Costco" << endl;
    bankAccount1->saveTransaction("Purchase", 1000);
    
    bankAccount1->showBalance();
    cout << endl;
}


