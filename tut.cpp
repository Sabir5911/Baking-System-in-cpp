// Bismillah rahman rahim  AllahuAkbar
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int signin(string firstname, string lastname, string pincode)
{

    string FirstName = "FirstName";
    string LastName = "LastName";
    string PinCode = "PinCode";

    fstream file("users.txt", ios::in);
    string userData;

    while (getline(file, userData))
    {

        if (userData == FirstName + " " + firstname + " " + LastName + " " + lastname + " " + PinCode + " " + pincode)
        {
            return true;
        };
    }
}

int signup()
{

    string FirstName, pincode, LastName;

    cout << "Enter your First Name" << endl;
    cin >> FirstName;
    cout << "Enter your Last Name" << endl;
    cin >> LastName;

    cout << "Enter Pin Code" << endl;
    cin >> pincode;
    if (signin(FirstName, pincode, LastName))
    {
        cout << "Dear"
             << " " << FirstName << " " << LastName << " "
             << "You account is already created please signup" << endl;
    }
    else
    {
        fstream files;
        files.open("users.txt", ios::app | ios::out);
        files << "FirstName"
              << " " << FirstName << " ";
        files << "LastName"
              << " " << LastName << " ";
        files << "PinCode"
              << " " << pincode << " " << endl;
    }
}

int main()
{

    while (true)
    {

        cout << "1. Sign Up\n2. Sign In\n3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            signup();
        }
        else if (choice == 2)
        {
            string FirstName, pincode, LastName;
            cout << "Enter your First Name" << endl;
            cin >> FirstName;
            cout << "Enter your Last Name" << endl;
            cin >> LastName;

            cout << "Enter Pin Code" << endl;
            cin >> pincode;

            if (signin(FirstName, LastName, pincode))
            {
                cout << "You are already login" << endl;
                int opt;
                cout << "1. Deposit Cash\n2. Withdraw Money\n3 .Check Balance Exit\n";
                cin >> opt;
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
