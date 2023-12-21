using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>

struct UserData
{
    std::string Firstname;
    std::string Lastname;
    std::string Pincode;
    int balance = 0;
};
void Data_Trs(string Firstname, string Lastname, string Pincode,
              string TFirst, string Tlast)
{
    UserData User, User2;
    bool flag = false;
    int data=0;
    std::fstream files;
    files.open("users.txt", std::ios::in);

    std::string Data, update;
    while (std::getline(files, Data))
    {
        std::istringstream iss(Data);
        std::istringstream is(Data);

        is >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;
        iss >> User2.Firstname >> User2.Lastname >> User2.Pincode >> User2.balance;

        // if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        // {
        //    data= User.balance;
        //     flag = true;
        // }

        if (flag == true)
        {
            if(TFirst==User2.Firstname && Tlast==User2.Lastname)
            {
                cout<<"Enter the amount you want to transfer: ";
                int amount;
                cin>>amount;
                if(amount>int(data))
                {
                    cout<<"Insufficient funds!"<<endl;
                }
                else
                {
                    User.balance-=amount;
                    User2.balance+=amount;
                }
            }
            else
            {
                cout<<"User not found"<<endl;
            }
            // std::cout << "Enter the amount you want to transfer: ";
            // int amount;
            // std::cin >> amount;

            cout <<(data) << endl;
            // if (amount > int(User.balance))
            // {
            //     std::cout << "Insufficient funds!" << std::endl;
            // }
            // else
            // {
            //     User.balance -= amount;
            //     User2.balance += amount;
            // }
        }

        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + std::to_string(User.balance) + " ";
        update += User2.Firstname + " " + User2.Lastname + " " + User2.Pincode + " " + std::to_string(User2.balance) + "\n";
    }

    // files.close();

    // files.open("users.txt", std::ios::out);
    // files << update;
    // files.close();
}

int CheckBal(std::string Firstname, std::string Lastname, std::string Pincode)
{
    UserData User;
    std::fstream file;
    file.open("users.txt", std::ios::in);
    std::string Data;

    while (std::getline(file, Data))
    {
        std::istringstream iss(Data);
        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            std::cout << User.balance << std::endl;
            return User.balance;
        }
    }
    return 0;
}

int Withdraw(std::string Firstname, std::string Lastname, std::string Pincode, int bal)
{
    UserData User;
    std::fstream files;
    files.open("users.txt", std::ios::in);
    std::string st, update;

    while (std::getline(files, st))
    {
        std::istringstream iss(st);
        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            if (bal > User.balance)
            {
                std::cout << "Are You Crazy?: " << std::endl;
            }
            else
            {
                User.balance -= bal;
            }
        }
        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + std::to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", std::ios::out);
    files << update;
    files.close();

    return 0;
}

int deposit(std::string Firstname, std::string Lastname, std::string Pincode, int bal)
{
    UserData User;
    std::fstream files;
    files.open("users.txt", std::ios::in);
    std::string st, update;

    while (std::getline(files, st))
    {
        std::istringstream iss(st);
        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;

        if (Firstname == User.Firstname && Lastname == User.Lastname && Pincode == User.Pincode)
        {
            User.balance = User.balance + bal;
        }
        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + std::to_string(User.balance) + "\n";
    }

    files.close();
    files.open("users.txt", std::ios::out);
    files << update;
    files.close();

    return 0;
}

bool signin(std::string Firstname, std::string Lastname, std::string Pincode)
{
    std::fstream files("users.txt", std::ios::in);
    std::string first, last, code, st;
    while (std::getline(files, st))
    {
        std::istringstream iss(st);
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
    std::cout << "Enter your First Name" << std::endl;
    std::cin >> User.Firstname;
    std::cout << "Enter your Last Name" << std::endl;
    std::cin >> User.Lastname;

    std::cout << "Enter Pin Code" << std::endl;
    std::cin >> User.Pincode;
    User.balance = 0;

    if (signin(User.Firstname, User.Lastname, User.Pincode))
    {
        std::cout << "Dear " << User.Firstname << " " << User.Lastname << " Your account is already created. Please sign in." << std::endl;
    }
    else
    {
        std::fstream files;
        files.open("users.txt", std::ios::app);
        files << User.Firstname << " " << User.Lastname << " " << User.Pincode << " " << User.balance << std::endl;
        files.close();
    }

    return 0;
}

int main()
{
    UserData Data, Data2;

    while (true)
    {
        std::cout << "1. Sign Up\n2. Sign In\n3. Check Bal\n4. Exit\n";
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            signup();
        }
        else if (choice == 2)
        {
            std::cout << "Enter your First Name" << std::endl;
            std::cin >> Data.Firstname;
            std::cout << "Enter your Last Name" << std::endl;
            std::cin >> Data.Lastname;

            std::cout << "Enter Pin Code" << std::endl;
            std::cin >> Data.Pincode;

            if (signin(Data.Firstname, Data.Lastname, Data.Pincode))
            {
                std::cout << "You are logged in" << std::endl;
                int opt;
                std::cout << "1. Deposit Cash\n2. Withdraw Money\n3. Check Balance\n4. Exit\n";
                std::cin >> opt;

                if (opt == 1)
                {
                    int amount;
                    std::cout << "Enter the amount you want to deposit: ";
                    std::cin >> amount;
                    deposit(Data.Firstname, Data.Lastname, Data.Pincode, amount);
                }
                else if (opt == 2)
                {
                    int amount;
                    std::cout << "Enter the amount you want to withdraw: ";
                    std::cin >> amount;
                    Withdraw(Data.Firstname, Data.Lastname, Data.Pincode, amount);
                }
                else if (opt == 3)
                {
                    std::cout << "Enter the name of the person you want to transfer to: ";
                    std::cin >> Data2.Firstname;
                    std::cout << "Enter the last name of the person you want to transfer to: ";
                    std::cin >> Data2.Lastname;
                    // CheckBal(Data.Firstname, Data.Lastname, Data.Pincode);
                    Data_Trs(Data.Firstname, Data.Lastname, Data.Pincode, Data2.Firstname, Data2.Lastname);
                }
                else if (opt == 4)
                {
                    break; // Exit the loop
                }
            }
            else
            {
                std::cout << "Invalid username or password. Please sign up first." << std::endl;
            }
        }
        else if (choice == 3)
        {
            std::cout << "Thanks for using ATM ";
            break; // Exit the loop
        }
        else if (choice == 4)
        {
            break; // Exit the loop
        }
    }

    return 0;
}
