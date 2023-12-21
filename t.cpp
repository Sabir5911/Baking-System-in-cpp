#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct UserData
{
    std::string Firstname;
    std::string Lastname;
    std::string Pincode;
    int balance = 0;
};

void Data_Trs(const std::string& Firstname, const std::string& Lastname, const std::string& Pincode,
              const std::string& TFirst, const std::string& Tlast)
{
    UserData User, User2;
    std::fstream files;
    files.open("users.txt", std::ios::in);

    std::string Data, update;
    while (std::getline(files, Data))
    {
        std::istringstream iss(Data);

        iss >> User.Firstname >> User.Lastname >> User.Pincode >> User.balance;
        iss >> User2.Firstname >> User2.Lastname >> User2.Pincode >> User2.balance;

       if (TFirst == User2.Firstname && Tlast == User2.Lastname)
            {
                std::cout << "Enter the amount you want to transfer: ";
                int amount;
                std::cin >> amount;

                if (amount > User.balance)
                {
                    std::cout << "Insufficient funds!" << std::endl;
                }
                else
                {
                    User.balance -= amount;
                    User2.balance += amount;
                }
            }
            else
            {
                std::cout << "Invalid username or password. Please sign up first." << std::endl;
            }
        

        // Update both users in the update string
        update += User.Firstname + " " + User.Lastname + " " + User.Pincode + " " + std::to_string(User.balance) + " ";
        update += User2.Firstname + " " + User2.Lastname + " " + User2.Pincode + " " + std::to_string(User2.balance) + "\n";
    }

    files.close();

    // Open the file for writing
    files.open("users.txt", std::ios::out);
    files << update;
    files.close();
}


int main()
{
    std::string FirstName, LastName, PinCode, TFirstName, TLastName;

    // Get input from the user (you may want to add more robust input validation)
    std::cout << "Enter your First Name: ";
    std::cin >> FirstName;
    std::cout << "Enter your Last Name: ";
    std::cin >> LastName;
    std::cout << "Enter your Pin Code: ";
    std::cin >> PinCode;

    std::cout << "Enter the name of the person you want to transfer to: ";
    std::cin >> TFirstName;
    std::cout << "Enter the last name of the person you want to transfer to: ";
    std::cin >> TLastName;

    // Call the function
    Data_Trs(FirstName, LastName, PinCode, TFirstName, TLastName);

    return 0;
}
