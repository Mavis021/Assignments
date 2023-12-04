#include <iostream>
#include <string>

class Account{

        protected:
        long int balance;
        std::string holderName;

        public:
        Account(std::string _name, long int _balance):holderName(_name), balance(_balance){}

        void viewBalance(){
                std::cout<< "\n\n REMAINING BALANCE : " << balance << "\n --------------------------------- \n";
        }
};

class Bank: public Account{

        private:
        long int accountId;

        public:
        Bank(std::string _name, long int _balance) : Account(_name, _balance), accountId(0000000021){
        }

        void withdraw(int amount){

                if (amount > 0 && amount <= balance){
                        balance -= amount;
                        std::cout << "\n VALID WITHDRAWAL \n VIEW BALANCE? (Y/n)\n";
                }
                else{
                        std::cout << "\n INVALID WITHDRAWAL ATTEMPT! \n VIEW BALANCE? (Y/n) \n";
                }
        }

        void deposit(int amount){
                if (amount > 0){
                        balance += amount;
                        std::cout << "\n VALID DEPOSIT \n VIEW BALANCE? (Y/n) \n";
                }
                else{
                        std::cout << "\n INVALID DEPOSIT ATTEMPT! \n VIEW BALANCE? (Y/n) \n";
                }
        }
};

void clear(){
        system("clear");
}

int main(){

        Bank customer("Zoro", 1111000000);

        char prompt = 'y', view, ch;
        int action, amt;
        while (prompt == 'y'){

                clear();

                std::cout<<"\n 1. WITHDRAWAL \n 2. DEPOSIT \n 3. VIEW BALANCE \n 4. EXIT\n \n CHOOSE AN ACTION: ";
                std::cin>> action;

                switch(action){
                        case 1:
                                clear();
                                std::cout << "\n ENTER WITHDRAWAL AMOUNT: ";
                                std::cin >> amt;
                                customer.withdraw(amt);
                                std::cin >> view;
                                if (view == 'y'){
                                        customer.viewBalance();
                                        std::cout<< "\n PRESS 'y' TO GET BACK TO MAIN MENU: ";
                                        std::cin >> ch;
                                }
                                break;

                        case 2:
                                clear();
                                std::cout << "\n ENTER DEPOSIT AMOUNT: ";
                                std::cin >> amt;
                                customer.deposit(amt);
                                std::cin >> view;
                                if (view == 'y'){
                                        customer.viewBalance();
                                        std::cout<< "\n PRESS 'y' TO GET BACK TO MAIN MENU: ";
                                        std::cin >> ch;
                                }
                                break;

                        case 3:
                                clear();
                                customer.viewBalance();
                                std::cout<< "\n PRESS 'y' TO GET BACK TO MAIN MENU: ";
                                std::cin >> ch;
                                break;

                        case 4:
                                std::cout << "\n exiting ... \n";
                                prompt = 'n';
                                break;

                        default:
                                std::cout<<"\n ERROR! exiting ... \n";
                }
        }

        return 0;
}
