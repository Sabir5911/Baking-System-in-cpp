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
};
struct User
{
    string Firstname;
    string Lastname;
   
};
int deposit(string Firstname, string Lastname, string Pincode, int bal)
{
    UserData User;
    fstream files;
    files.open("users.csv", ios::in);

    string st, update;
    while (getline(files, st))
    {
        istringstream iss(st);

        getline(iss, User.Firstname, ',');
        getline(iss, User.Lastname, ',');
        getline(iss, User.Pincode, ',');
        getline(iss, st, ',');

        User.balance = stoi(st); // Convert balance string to integer

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            User.balance += bal;
        }
        update += User.Firstname + "," + User.Lastname + "," + User.Pincode + "," + to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.csv", ios::out | ios::trunc); 

    ofstream updateFils("users.csv");
    updateFils << update;

    cout << "Your data updated. New balance: " << User.balance << endl;
}

int signin(string Firstname, string Lastname, string Pincode)
{
    fstream files("users.csv", ios::in);
    string first, last, code, balance_str, st;
    
    while (getline(files, st))
    {
        istringstream iss(st);
        getline(iss, first, ',');
        getline(iss, last, ',');
        getline(iss, code, ',');
        getline(iss, balance_str, ',');
        
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
        files.open("users.csv", ios::app);

        files << User.Firstname << "," << User.Lastname << "," << User.Pincode << "," << User.balance << endl;
    }
}

int main()
{
    string FirstName, pincode, LastName;
    while (true)
    {
        cout << "1. Sign Up\n2. Sign In\n3. Exit\n";
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
            cin >> FirstName;
            cout << "Enter your Last Name" << endl;
            cin >> LastName;

            cout << "Enter Pin Code" << endl;
            cin >> pincode;

            if (signin(FirstName, LastName, pincode))
            {
                cout << "You are  login" << endl;
                int opt;
                cout << "1. Deposit Cash\n2. Withdraw Money\n3 .Check Balance Exit\n";
                cin >> opt;

                if (opt == 1)
                {
                    int amount;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> amount;
                    deposit(FirstName, LastName, pincode, amount);
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
            break;
        }
        }
}