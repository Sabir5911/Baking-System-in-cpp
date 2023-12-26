#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <unistd.h>
#include <chrono>
using namespace std;


struct UserData
{
    string Firstname;
    string Lastname;
    string Pincode;
    int id_number;
    int balance = 0;
};
bool signin(int U_d, string password)
{
    fstream files("users.txt", ios::in);
    string U_id, first, last, code, st;
    while (getline(files, st))
    {
        istringstream iss(st);
        iss >> U_id >> first >> last >> code;

        if (U_id == to_string(U_d) && code == password)
        {
            files.close();
            return true;
        }
    }
    return false;
}

void loadingAnimation()
{
    cout << "Loading";
    for (int i = 0; i < 3; ++i)
    {
        cout << ".";
        sleep(1000);

    }
    cout << endl;
}

void errorAnimation(const string& message)
{
    cout << "Error: " << message << endl;
    sleep(2000);
}

void displayMenu()
{
    cout << "1. Sign Up\n2. Sign In\n3. Check Balance\n4. Exit\n";
}

void signUp()
{
    UserData User;
    cout << "Enter your First Name: ";
    cin >> User.Firstname;
    cout << "Enter your Last Name: ";
    cin >> User.Lastname;
    cout << "Enter Pin Code: ";
    cin >> User.Pincode;
    User.balance = 0;

    srand(time(nullptr));
    User.id_number = rand();

    if (signin(User.id_number, User.Pincode))
    {
        cout << "Dear " << User.Firstname << " " << User.Lastname << " Your account is already created. Please sign in." << endl;
    }
    else
    {
        fstream files;
        files.open("users.txt", ios::app);
        files << User.id_number << " " << User.Firstname << " " << User.Lastname << " " << User.Pincode << " " << User.balance << endl;
        files.close();
        loadingAnimation();
        cout << "Account created successfully!\n";
    }
}

bool signIn(int U_d, string password)
{
    fstream files("users.txt", ios::in);
    string U_id, first, last, code, st;
    while (getline(files, st))
    {
        istringstream iss(st);
        iss >> U_id >> first >> last >> code;

        if (U_id == to_string(U_d) && code == password)
        {
            files.close();
            return true;
        }
    }
    return false;
}

void deposit(int id_number, string Pincode, int bal)
{
    UserData User;
    fstream files;
    files.open("users.txt", ios::in);
    string st, update;

    while (getline(files, st))
    {
        istringstream iss(st);
        iss >> User.id_number >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (id_number == User.id_number && Pincode == User.Pincode)
        {
            User.balance += bal;
        }
        update += to_string(User.id_number) + " " + User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", ios::out);
    files << update;
    files.close();

    loadingAnimation();
    cout << "Deposit successful! Current balance: " << User.balance << "\n";
}

void withdraw(int id_number, string Pincode, int bal)
{
    UserData User;
    fstream files;
    files.open("users.txt", ios::in);
    string st, update;

    while (getline(files, st))
    {
        istringstream iss(st);
        iss >> User.id_number >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (id_number == User.id_number && Pincode == User.Pincode)
        {
            if (bal > User.balance)
            {
                errorAnimation("Insufficient funds");
                return;
            }
            else
            {
                User.balance -= bal;
            }
        }
        update += to_string(User.id_number) + " " + User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", ios::out);
    files << update;
    files.close();

    loadingAnimation();
    cout << "Withdrawal successful! Current balance: " << User.balance << "\n";
}

void transfer(int id, int id2, string pass, int amount = 8)
{
    UserData User, User2;

    fstream files;
    files.open("users.txt", ios::in);

    bool found = false;
    string Data, update;

    while (getline(files, Data))
    {
        istringstream iss(Data);
        iss >> User.id_number >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (id == User.id_number && pass == User.Pincode)
        {
            found = true;
            User.balance -= amount;
        }

        update += to_string(User.id_number) + " " + User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
    }
    files.close();

    files.open("users.txt", ios::out);
    files << update;
    files.close();

    files.open("users.txt", ios::in);

    string update2;

    while (getline(files, Data))
    {

        istringstream is(Data);

        is >> User2.id_number >> User2.Firstname >> User2.Lastname >> User2.Pincode >> User2.balance;

        if (User2.id_number == id2 && found)
        {
            cout << "Updating balance..." << endl;
            User2.balance += amount;
        }
        else
        {
            cout << "Skipping update..." << endl;
        }

        update2 += to_string(User2.id_number) + " " + User2.Firstname + " " + User2.Lastname + " " + User2.Pincode + " " + to_string(User2.balance) + "\n";
    }

    files.close();

    files.open("users.txt", ios::out);
    files << update2;
    files.close();
}

int checkBalance(int id_number, string Pincode)
{
    UserData User;
    fstream file;
    file.open("users.txt", ios::in);
    string Data;

    while (getline(file, Data))
    {
        istringstream iss(Data);
        iss >> User.id_number >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (id_number == User.id_number && Pincode == User.Pincode)
        {
            return User.balance;
        }
    }

    return -1; // Return -1 if user not found
}

int main()
{
    UserData Data;

    while (true)
    {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            signUp();
            break;

        case 2:
            cout << "id: ";
            cin >> Data.id_number;
            cout << "pss: ";
            cin >> Data.Pincode;
            if (signIn(Data.id_number, Data.Pincode))
            {
                cout << "You are logged in" << endl;
                int opt;
                cout << "1. Deposit Cash\n2. Withdraw Money\n3. Transfer Money\n4. Exit\n";
                cin >> opt;

                switch (opt)
                {
                case 1:
                    int amount;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> amount;
                    deposit(Data.id_number, Data.Pincode, amount);
                    break;

                case 2:
                    int withdrawalAmount;
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> withdrawalAmount;
                    withdraw(Data.id_number, Data.Pincode, withdrawalAmount);
                    break;

                case 3:
                    int receiverId;
                    cout << "Enter the account ID you want to transfer to: ";
                    cin >> receiverId;
                    int transferAmount;
                    cout << "Enter the amount you want to transfer: ";
                    cin >> transferAmount;
                    transfer(Data.id_number, receiverId, Data.Pincode, transferAmount);
                    break;

                case 4:
                    break;

                default:
                    errorAnimation("Invalid option");
                    break;
                }
            }
            else
            {
                errorAnimation("Invalid username or password. Please sign up first.");
            }
            break;

        case 3:
            cout << "Thanks for using ATM\n";
            break;

        case 4:
            return 0;

        default:
            errorAnimation("Invalid option");
            break;
        }
    }

    return 0;
}
