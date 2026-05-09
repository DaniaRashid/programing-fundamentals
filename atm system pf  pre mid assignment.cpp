#include <iostream>
using namespace std;

int main() {
    int pin, attempts = 0;
    int correctPIN = 1234;
    double balance = 1000;   // initial balance
    int choice;
    double amount;
    string lastTransaction = "None";
    double lastAmount = 0;



    // Welcome Screen

    cout << "\n==============================" << endl;
    cout << "   Welcome to Simple ATM" << endl;
    cout << "==============================" << endl;

    // PIN Verification (max 3 attempts)
    while (attempts < 3) {
        cout << "\nEnter your PIN: ";
        cin >> pin;

        if (pin == correctPIN) {
            cout << "PIN verified successfully!" << endl;

            // Main Menu loop
            do {
                cout << "\n===== Main Menu =====" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit Money" << endl;
                cout << "3. Withdraw Money" << endl;
                cout << "4. Mini Statement " << endl;
                cout << "5. Exit" << endl;
                cout << "\nEnter your choice: ";
                cin >> choice;

                // Operations 

                switch (choice) {
                case 1:
                    cout << "\nCurrent Balance: " << balance << endl;
                    break;

                case 2:
                    cout << "\nEnter amount to deposit: ";
                    cin >> amount;
                    if (balance + amount < balance) { // overflow check
                        cout << "Error: Balance overflow!" << endl;
                    }
                    else {
                        balance += amount;
                        cout << "Deposited: " << amount << endl;
                        cout << "New Balance: " << balance << endl;
                        lastTransaction = "Deposit";
                        lastAmount = amount;

                    }
                    break;

                case 3:
                    cout << "\nEnter amount to withdraw: ";
                    cin >> amount;
                    if (amount > balance) {
                        cout << "\nError: Insufficient funds!" << endl;
                    }
                    else {
                        balance -= amount;
                        cout << "\nWithdrawn: " << amount << endl;
                        cout << "\nNew Balance: " << balance << endl;
                        lastTransaction = "Withdraw";
                        lastAmount = amount;

                    }
                    break;

                case 4:
                    cout << "\n=== Mini Statement ===" << endl;
                    if (lastTransaction == "Deposit") {
                        cout << "\nLast Transaction: Deposit of " << lastAmount << endl;
                    }
                    else if (lastTransaction == "Withdraw") {
                        cout << "\nLast Transaction: Withdrawal of " << lastAmount << endl;
                    }
                    else {
                        cout << "\nNo transactions yet." << endl;
                    }
                    break;


                case 5:
                    cout << "\nThank you for using the ATM. Goodbye!" << endl;
                    break;

                default:
                    cout << "\nInvalid choice. Please try again." << endl;
                }
            } while (choice != 5);

            return 0;
        }
        else {
            // postfix increment (attemps++)
            cout << "\nIncorrect PIN. Attempts left: " << 3 - attempts << endl;
            attempts++;

            // prefix decrement (--remaining)
            int remaining = 3 - attempts;
            --remaining;
            cout << "(remaining attempts after -- =" << remaining << "\n";

        }
    }

    cout << "\nToo many incorrect attempts. ATM locked!" << endl;
    return 0;
}