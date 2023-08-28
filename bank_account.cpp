#include<iostream>
using std::string;

class BankAccount {
    private:
        int AccNumber;
        float Balance;
    public:
        BankAccount(int accNum, float balance) {
            AccNumber = accNum;
            Balance = balance;
        }

        void deposit(float amount) {
            Balance += amount;
            std::cout << "Succesfully deposited "<<amount<<"$ to your account!"<<std::endl;
        }

        void withdraw(float amount) {
            if (amount>Balance) {
                std::cout << "Sorry, you cannot withdraw that much money."<<std::endl;
            }
            else {
                Balance -= amount;
                std::cout << "Succesfully withdrawed "<<amount<<"$ from your account!"<<std::endl;
            }
        }

        float get_balance() {
            return Balance;
        }
};

int main() {
    BankAccount account = BankAccount(1,0);

    while (true) {
        int user_choice;
        std::cout << "1.Deposit money\n2.Withdraw money\n3.View balance"<<std::endl;
        std::cin >> user_choice;

        switch (user_choice) {
            case 1:
                int dep_amount;
                std::cout << "How much do you want to deposit: "<<std::endl;
                std::cin >> dep_amount;
                account.deposit(dep_amount);
                break;

            case 2:
                int with_amount;
                std::cout << "How much do you want to withdraw: "<<std::endl;
                std::cin >> with_amount;
                account.withdraw(with_amount);
                break;

            case 3:
                std::cout << "Balance: "<<account.get_balance()<<"$"<<std::endl;
                break;

            default:
                std::cout << "Type in 1, 2 or 3"<<std::endl;
                break;
        }
        
        std::cout << "----------------------------"<<std::endl;
    }
    
}