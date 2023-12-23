using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
struct UserData
{
    string Firstname;
    string Lastname;
    string Pincode;
    int id_number;
    int balance = 0;
};
void Data_Trs( int id,  int id2 ,string pass, int amount = 8)
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

        if (User2.id_number == id2  && found)
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
void CheckBal(int id_number, string Pincode)
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
            cout << User.balance << endl;
           
        }
    }
}

int Withdraw(int id_number, string Pincode, int bal)
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
                cout << "Are You Crazy?: " << endl;
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

    return 0;
}

int deposit(int id_number, string Pincode, int bal)
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
            User.balance = User.balance + bal;
        }
        update += to_string(User.id_number) + " " + User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", ios::out);
    files << update;
    files.close();

    return 0;
}

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

    User.balance = 0;
    srand(time(nullptr));
    int a = rand();
    User.id_number = a;
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
    }

    return 0;
}

int main()
{
    UserData Data;

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
            cout << "id: ";
            cin >> Data.id_number;
            cout << "pss: ";
            cin >> Data.Pincode;
            if (signin(Data.id_number, Data.Pincode))
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
                    deposit(Data.id_number, Data.Pincode, amount);
                }
                else if (opt == 2)
                {
                    int amount;
                    cout << "Enter the amount you want to withdraw: ";
                    cin >> amount;
                    Withdraw(Data.id_number, Data.Pincode,  amount);
                }
                else if (opt == 3)
                {
                    int acc;
                    cout << "Enter the name of the acc you want to transfer to: ";
                 cin>>acc;
                    int amount;
                    cout << "Enter the amount you want to transfer: ";
                    cin >> amount;
                    // CheckBal(Data.Firstname, Data.Lastname, Data.Pincode);
                    Data_Trs(Data.id_number, acc, Data.Pincode, amount);
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

}
