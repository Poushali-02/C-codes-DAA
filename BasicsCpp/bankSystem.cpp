#include <iostream>
#include <string>
using namespace std;

class Bank {
    private:
        string accHolderName;
        int accNumber;
        double accBalance;

    public:
        Bank():                  // default constructor
            accNumber(0), 
            accBalance(0.0), 
            accHolderName("xyz") 
        {}

        // getter for account holder name
        string getAccHolderName(){
            return this->accHolderName;
        }
        
        // setter for account holder name
        void setAccHolderName(string accHolderName){
            this->accHolderName = accHolderName;
            cout << "Successfully set account holder name." << endl;
        }

        // getter for account number
        int getAccNumber(){
            return this->accNumber;
        }

        // setter for account number
        void setAccNumber(int accNumber){
            if(accNumber > 0){
                this->accNumber = accNumber;
                cout << "Successfully set account number." << endl;
            }
            else {
                cout << "Invalid account number" << endl;
                return;
            }
        }

        // getter for account balance
        double getAccBalance(){
            return this->accBalance;
        }
        // setter for account balance
        void setAccBalance(double accBalance){
            if(accBalance > 0.0){
                this->accBalance = accBalance;            
                cout << "Successfully set account balance" << endl;
            }else {
                cout << "Invalid account balance to set" << endl;
                return;
            }
        }

        // deposit function
        void deposit(double depAmount){
            if (depAmount > 0.0){
                double currBalance = getAccBalance();
                double totalBalance = currBalance + depAmount;
                setAccBalance(totalBalance);

                cout << "Depositted " << depAmount << " Rupee.\n";
            }
            else {
                cout << "Invalid amount to deposit\n";
                return;
            }
        }

        // withdraw function
        void withdraw(double withDrawAmount){

            double accBal = getAccBalance();
            double restBal = -1;

            if(withDrawAmount > 0.0){
                restBal = accBal - withDrawAmount;
            }
            else {
                cout << "Invalid amount to withdraw\n";
                return;
            }

            if(restBal > 0.0){
                // withdraw valid
                setAccBalance(restBal);
                cout << "Successfully withdrawn " << withDrawAmount <<  " Rupee\n";
            }
            else {
                cout << "Insufficient account balance\n";
                return;
            }
        }
        // display method
        void display(){
            cout << "Account Holder's informations\n";
            cout << "Account Holder's name : " << getAccHolderName() << endl;
            cout << "Account Holder's account number : " << getAccNumber() << endl;
            cout << "Account Holder's account balance : " << getAccBalance() << endl;
            
        }
};

class SavingAccount : public Bank{
    private:
        double interestRate;

    public:
        SavingAccount():  // default constructor
            Bank(), 
            interestRate(0.0) 
        {};

        // setter for interest rate
        void setInterestRate(double rate){
            this->interestRate = rate;
        }

        // getter for interest rate
        double getInterestRate(){
            return this->interestRate;
        }

        // apply interest
        void applyInterest(double rate){
            if(rate > 0.0){
                double currBalance = getAccBalance();
                double interest = (currBalance * rate) / 100;
                setAccBalance(currBalance + interest);
                cout << "Successfully applied " << rate << "%" <<" interest";
            }
            else {
                cout << "Invalid rate amount";
                return;
            }
        }
};
int main() {
        // Create Bank account
    Bank bank;
    bank.setAccHolderName("Poushali Bhattacharyya");
    bank.setAccNumber(123456789);
    bank.deposit(5000.0);
    
    cout << "\n--- Bank Account ---" << endl;
    bank.display();
    
    bank.withdraw(1500.0);
    cout << "\nAfter withdrawal:" << endl;
    bank.display();
    
    // Create Savings account
    SavingAccount s;
    s.setAccHolderName("Priya Singh");
    s.setAccNumber(67890);
    s.deposit(10000.0);
    s.setInterestRate(5.0);
    
    cout << "\n--- Savings Account ---" << endl;
    s.display();
    
    s.applyInterest(5.0);
    cout << "\nAfter interest:" << endl;
    s.display();
    
    return 0;
}