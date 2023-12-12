// Bismillah rahman rahim  AllahuAkbar
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <sstream>

struct UserData
{
    string Firstname;
    string Lastname;
    string Pincode;
    int balance = 0;
    static int objectCounter;
    UserData()
    {
        objectCounter++;
    }
};

int UserData::objectCounter = 0;

int CheckBal(string Firstname, string Lastname, string Pincode)
{

    UserData User;
    int UserData = 0;
    fstream file;
    file.open("users.txt", ios::in);
    string Data, ip;
    while (getline(file, Data))
    {
        istringstream iss(Data);

        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;
        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            cout << User.balance << endl;
        }
    }
}

int Withdraw(string Firstname, string Lastname, string Pincode, int bal)
{

    UserData User;
    fstream files;
    files.open("users.txt", ios::in);
    string st, update;
    while (getline(files, st))
    {
        istringstream iss(st);

        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            if (bal > User.balance)
            {
                cout << "Are You Crazy?: " << endl;
            }
            else
            {
                User.balance -= bal;
            }
        }
        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", ios::out);

    ofstream updateFils("users.txt");
    updateFils << update;
}

int deposit(string Firstname, string Lastname, string Pincode, int bal)
{

    UserData User;
    fstream files;
    files.open("users.txt", ios::in);
    string st, update;
    while (getline(files, st))
    {
        istringstream iss(st);

        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            User.balance = User.balance + bal;
        }
        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", ios::out);

    ofstream updateFils("users.txt");
    updateFils << update;
}

int signin(string Firstname, string Lastname, string Pincode)
{
    fstream files("users.txt", ios::in);
    string first, last, code, st;
    while (getline(files, st))
    {
        istringstream iss(st);

        iss >> first >> last >> code;

        if (Firstname == first && Lastname == last && Pincode == code)
        {
            return true;
        }
    }
    return false;
}

int signup()
{
    UserData User;
    cout << "Enter your First Name" << endl;
    cin >> User.Firstname;
    cout << "Enter your Last Name" << endl;
    cin >> User.Lastname;

    cout << "Enter Pin Code" << endl;
    cin >> User.Pincode;
    User.balance = 0;

    if (signin(User.Firstname, User.Lastname, User.Pincode))
    {
        cout << "Dear"
             << " " << User.Firstname << " " << User.Lastname << " "
             << "You account is already created please sign" << endl;
    }
    else
    {
        fstream files;
        files.open("users.txt", ios::app);

        files << User.Firstname << " " << User.Lastname << " " << User.Pincode << " " << User.balance << endl;
    }
}

int main()
{
    UserData Data;
    while (true)
    {
        cout << "1. Sign Up\n2. Sign In\n3.\n4 Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            signup();
        }
        else if (choice == 2)
        {
            cout << "Enter your First Name" << endl;
            cin >> Data.Firstname;
            cout << "Enter your Last Name" << endl;
            cin >> Data.Lastname;

            cout << "Enter Pin Code" << endl;
            cin >> Data.Pincode;

            if (signin(Data.Firstname, Data.Lastname, Data.Pincode))
            {
                cout << "You are  login" << endl;
                int opt;
                cout << "1. Deposit Cash\n2. Withdraw Money\n3 .Check Balance \nExit\n";
                cin >> opt;

                if (opt == 1)
                {
                    int amount;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> amount;
                    deposit(Data.Lastname, Data.Lastname, Data.Pincode, amount);
                }
                else if (opt == 2)
                {
                    int amount;

                    cout << "Enter the amount you want to Withdraw: ";
                    cin >> amount;

                    Withdraw(Data.Firstname, Data.Lastname, Data.Pincode, amount);
                }
                else if (opt == 3)
                {
                    CheckBal(Data.Firstname, Data.Lastname, Data.Pincode);
                }
            }
            else
            {
                cout << "Invalid username or password. Please sign up first." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "thanks for using atm ";

            fstream file;
            UserData Data;
            file.open("Total.txt", ios::app);
            file << "Total Ac: " << Data.objectCounter;
            break;
        }
    }
}
