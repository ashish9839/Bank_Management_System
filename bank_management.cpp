#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int total_saving_accounts = 0;
int total_current_accounts = 0;

class account {
public:
    string name_of_account_holder;
    string name_of_joint_account_holder;
    long long int account_number;
    int balance;
    string type_of_account;
    string pin;

    account(string accholdername, int bal, string typeofacc, string pc) {
        account_number = rand() % 9000000000 + 1000000000;
        name_of_account_holder = accholdername;
        balance = bal;
        type_of_account = typeofacc;
        pin = pc;
        name_of_joint_account_holder = "No Joint Holder in this account";
    }

    account(string accholdername, string jointholdername, int bal, string typeofacc, string pc) {
        account_number = rand() % 9000000000 + 1000000000;
        name_of_account_holder = accholdername;
        name_of_joint_account_holder = jointholdername;
        balance = bal;
        type_of_account = typeofacc;
        pin = pc;
    }
};

vector<account> accts;

void display_details(long long int accnum) {
    for (auto &it : accts) {
        if (it.account_number == accnum) {
            cout << "\nAccount Number: " << it.account_number;
            cout << "\nAccount Holder Name: " << it.name_of_account_holder;
            cout << "\nJoint Holder Name: " << it.name_of_joint_account_holder;
            cout << "\nBalance: " << it.balance;
            cout << "\nType of Account: " << it.type_of_account << "\n";
            return;
        }
    }
    cout << "Account doesn't exist with the given Account Number.\n";
}

bool create_account() {
    string accholder_name, joint_holder, pin, typeofacc;
    int balance, choice;

    cout << "\nENTER YOUR DETAILS HERE:";
    cout << "\nName of Account Holder: ";
    cin >> accholder_name;
    
    cout << "\nDo you want a joint holder account? Type YES/NO: ";
    string str;
    cin >> str;

    bool is_joint = (str == "YES");
    if (is_joint) {
        cout << "Enter the name of Joint Holder: ";
        cin >> joint_holder;
    }

    cout << "\nEnter a 4-digit PIN: ";
    cin >> pin;

    cout << "\nEnter the type of account:\n1 - Savings Account\n2 - Current Account\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    typeofacc = (choice == 1) ? "Savings" : "Current";

    cout << "\nEnter the initial balance: ";
    cin >> balance;

    if (typeofacc == "Current" && balance < 10000) {
        cout << "INSUFFICIENT BALANCE for Current Account (Minimum required: 10,000)\n";
        return false;
    }

    if (is_joint) {
        accts.emplace_back(accholder_name, joint_holder, balance, typeofacc, pin);
    } else {
        accts.emplace_back(accholder_name, balance, typeofacc, pin);
    }

    if (typeofacc == "Savings") total_saving_accounts++;
    else total_current_accounts++;

    cout << "ACCOUNT CREATED SUCCESSFULLY!\n";
    display_details(accts.back().account_number);
    return true;
}

bool change_pin() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto &it : accts) {
        if (it.account_number == accnum) {
            string oldpin, newpin;
            cout << "Enter old PIN: ";
            cin >> oldpin;

            if (oldpin == it.pin) {
                cout << "Enter new PIN: ";
                cin >> newpin;
                it.pin = newpin;
                cout << "PIN changed successfully!\n";
                return true;
            } else {
                cout << "Invalid PIN. Try again.\n";
                return false;
            }
        }
    }
    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

bool deposit_into_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto &it : accts) {
        if (it.account_number == accnum) {
            string pin;
            cout << "Enter PIN: ";
            cin >> pin;

            if (pin == it.pin) {
                int deposit_amount;
                cout << "Enter deposit amount: ";
                cin >> deposit_amount;

                it.balance += deposit_amount;
                cout << "Deposit successful!\n";
                display_details(it.account_number);
                return true;
            } else {
                cout << "Invalid PIN. Try again.\n";
                return false;
            }
        }
    }
    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

bool withdraw_from_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto &it : accts) {
        if (it.account_number == accnum) {
            string pin;
            cout << "Enter PIN: ";
            cin >> pin;

            if (pin == it.pin) {
                int withdrawal_amount;
                cout << "Enter withdrawal amount: ";
                cin >> withdrawal_amount;

                if (it.balance - withdrawal_amount >= 0) {
                    it.balance -= withdrawal_amount;
                    cout << "Withdrawal successful!\n";
                    display_details(it.account_number);
                    return true;
                } else {
                    cout << "Insufficient balance!\n";
                    return false;
                }
            } else {
                cout << "Invalid PIN. Try again.\n";
                return false;
            }
        }
    }
    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

void display_menu() {
    cout << "\n******************************";
    cout << "\n*        BANK MENU          *";
    cout << "\n******************************";
    cout << "\n* 1. Create Account         *";
    cout << "\n* 2. Deposit                *";
    cout << "\n* 3. Withdraw               *";
    cout << "\n* 4. Change PIN             *";
    cout << "\n* 5. Exit                   *";
    cout << "\n******************************\n";
}

int main() {
    int choice;
    while (true) {
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create_account(); break;
            case 2: deposit_into_account(); break;
            case 3: withdraw_from_account(); break;
            case 4: change_pin(); break;
            case 5: exit(0);
            default: cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
