using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>

struct UserData
{
    string Firstname;
    string Lastname;
    string Pincode;
    int balance = 0;
};
void Data_Trs(string Firstname, string Lastname, string Pincode,
              string TFirst, string Tlast, int amount = 8)
{
    UserData User, User2;

    fstream files;
    files.open("users.txt", ios::in);

    bool found = false;
    string Data, update;
    while (getline(files, Data))
    {
        istringstream iss(Data);
        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            found = true;
            User.balance -= amount;
        }

        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
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

        is >> User2.Firstname >> User2.Lastname >> User2.Pincode >> User2.balance;

        if (User2.Firstname == TFirst && User2.Lastname == Tlast && found)
        {
            cout << "Updating balance..." << endl;
            User2.balance += amount;
        }
        else
        {
            cout << "Skipping update..." << endl;
        }

        update2 += User2.Firstname + " " + User2.Lastname + " " + User2.Pincode + " " + to_string(User2.balance) + "\n";
    }

    files.close();

    files.open("users.txt", ios::out);
    files << update2;
    files.close();
}
int CheckBal(string Firstname, string Lastname, string Pincode)
{
    UserData User;
    fstream file;
    file.open("users.txt", ios::in);
    string Data;

    while (getline(file, Data))
    {
        istringstream iss(Data);
        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            cout << User.balance << endl;
            return User.balance;
        }
    }
    return 0;
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
    files << update;
    files.close();

    return 0;
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
    files << update;
    files.close();

    return 0;
}

bool signin(string Firstname, string Lastname, string Pincode)
{
    fstream files("users.txt", ios::in);
    string first, last, code, st;
    while (getline(files, st))
    {
        istringstream iss(st);
        iss >> first >> last >> code;

        if (Firstname == first && Lastname == last && Pincode == code)
        {
            files.close();
            return true;
        }
    }
    files.close();
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
        cout << "Dear " << User.Firstname << " " << User.Lastname << " Your account is already created. Please sign in." << endl;
    }
    else
    {
        fstream files;
        files.open("users.txt", ios::app);
        files << User.Firstname << " " << User.Lastname << " " << User.Pincode << " " << User.balance << endl;
        files.close();
    }

    return 0;
}

int main()
{
    UserData Data, Data2;

    while (true)
    {
        cout << "1. Sign Up\n2. Sign In\n3. Check Bal\n4. Exit\n";
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
                cout << "You are logged in" << endl;
                int opt;
                cout << "1. Deposit Cash\n2. Withdraw Money\n3. Check Balance\n4. Exit\n";
                cin >> opt;

                if (opt == 1)
                {
                    int amount;
                    cout << "Enter the amount you want to deposit: ";
                    cin >> amount;
                    deposit(Data.Firstname, Data.Lastname, Data.Pincode, amount);
                }
                else if (opt == 2)
                {
                    int amount;
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> amount;
                    Withdraw(Data.Firstname, Data.Lastname, Data.Pincode, amount);
                }
                else if (opt == 3)
                {
                    string Firstname, Lastname;
                    cout << "Enter the name of the person you want to transfer to: ";
                    cin >> Firstname;
                    cout << "Enter the last name of the person you want to transfer to: ";
                    cin >> Lastname;
                    int amount;
                    cout << "Enter the amount you want to transfer: ";
                    cin >> amount;
                    // CheckBal(Data.Firstname, Data.Lastname, Data.Pincode);
                    Data_Trs(Data.Firstname, Data.Lastname, Data.Pincode, Firstname, Lastname, amount);
                }
                else if (opt == 4)
                {
                    break; 
                }
            }
            else
            {
                cout << "Invalid username or password. Please sign up first." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Thanks for using ATM ";
            break; 
        }
        else if (choice == 4)
        {
            break; 
        }
    }

    return 0;
}
