#include <iostream>
#include <string>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n*** ATM Menu ***" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
}

class ATM {
private:
    string pin = "1234";  // Predefined PIN for simplicity
    double balance = 1000;  // Initial balance

public:
    bool authenticate(string enteredPin) {
        if (enteredPin == pin) {
            return true;
        } else {
            cout << "Incorrect PIN. Please try again." << endl;
            return false;
        }
    }

    void checkBalance() {
        cout << "Your balance is: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "You have successfully deposited: $" << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "You have successfully withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
    }
};

int main() {
    ATM atm;
    string enteredPin;
    int choice;
    double amount;

    // PIN authentication
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (!atm.authenticate(enteredPin)) {
        return 0;  // Exit if PIN is incorrect
    }

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}




