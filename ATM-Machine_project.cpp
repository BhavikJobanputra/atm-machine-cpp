#include <iostream>
#include <string>
using namespace std;

class Banking_System
{
    struct Account
    {
        string name;
        int phone_number;
        float balance;
        string blood_group;
    };

    Account accounts[50];
    int num_accounts;               

public:
    Banking_System(){num_accounts=0;}
    
    void open_acc()
    {
        if (num_accounts<50)
        {
            cout << "Enter your Name:" << endl;
            cin >> accounts[num_accounts].name;
            cout << "Enter your Mobile/Phone number:" << endl;
            cin >> accounts[num_accounts].phone_number;
            cout << "Enter your Balance:" << endl;
            cin >> accounts[num_accounts].balance;
            cout << "Enter your Blood Group:" << endl;
            cin >> accounts[num_accounts].blood_group;
            cout << "Congratulations your Account is now opened with Account Number: " << num_accounts + 1 << endl;
            num_accounts++;
        }
        else
        {
            cout << "Maximum number of accounts reached." << endl;
        }
    }

    void close_acc(int acc_no)
    {
        if (acc_no > 0 && acc_no <= num_accounts)
        {
            for (int i = acc_no - 1; i < num_accounts - 1; i++)
            {
                accounts[i] = accounts[i + 1];
            }
            num_accounts--;
            cout << "Your Account with Account Number: " << acc_no << " is now Closed" << endl;
        }
        else
        {
            cout << "Invalid Account Number" << endl;
        }
    }

    void withdraw(int acc_no, float amount)
    {
        if (acc_no > 0 && acc_no <= num_accounts)
        {
            if (amount <= accounts[acc_no - 1].balance)
            {
                accounts[acc_no - 1].balance -= amount;
                cout << "Your amount is Processing" << endl;
                cout << "You got your Amount" << endl;
            }
            else
            {
                cout << "Insufficient balance" << endl;
            }
        }
        else
        {
            cout << "Invalid Account Number" << endl;
        }
    }

    void deposit(int acc_no, float amount)
    {
        if (acc_no > 0 && acc_no <= num_accounts)
        {
            accounts[acc_no - 1].balance += amount;
            cout << "Your amount is now deposited" << endl;
        }
        else
        {
            cout << "Invalid Account Number" << endl;
        }
    }
};

int main()
{
    Banking_System bank;
    int x;
    while (true)
    {
        cout << "Enter your choice: " << endl;
        
        cout << "1. Open Account " << endl;
        cout << "2. Close Account " << endl;
        cout << "3. Withdraw " << endl;
        cout << "4. Deposit " << endl;
        cout << "5. Exit " << endl;

        cin >> x;
        switch (x)
        {
        case 1:
            bank.open_acc();
            break;
        case 2:
            int closeAccNo;
            cout << "Enter account number to close: ";
            cin >> closeAccNo;
            bank.close_acc(closeAccNo);
            break;
        case 3:
            int withdrawAccNo;
            float withdrawAmount;
            cout << "Enter account number: ";
            cin >> withdrawAccNo;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;
            bank.withdraw(withdrawAccNo, withdrawAmount);
            break;
        case 4:
            int depositAccNo;
            float depositAmount;
            cout << "Enter account number: ";
            cin >> depositAccNo;
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            bank.deposit(depositAccNo, depositAmount);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}