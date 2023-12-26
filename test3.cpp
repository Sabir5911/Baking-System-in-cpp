#include <iostream>
#include <limits>   // for numeric_limits
#include <windows.h> // for Sleep function

using namespace std;

int display() {
    while (true) {
        cout << "\033[32m"; // ANSI_GREEN
        cout << "      __________________________\n";
        cout << "     | BANKING SYSTEM IN C++     |\n";
        cout << "     |      FUNCTIONALITY        |\n";
        cout << "     | login/SignUp/CheckBalance |\n";
        cout << "     | CHECK balance/TRANSFER    | \n";
        cout << "     |___________________________|\n"
             << "\033[0m"; // Reset color

        cout << "          |  |  |  |  |  | \n";
        cout << "        __|__|__|__|__|__|__\n";
        cout << "       |  |  |  |  |  |  |  |\n";
        cout << "      _|__|__|__|__|__|__|__|_\n"
             << "\033[32m"; // ANSI_GREEN

        cout << "      _________________________\n";
        cout << "     | PROGRAMMING fUNDAMENTALS|\n";
        cout << "     |    SEMESTER Project     |\n";
        cout << "     |MADE BY Sabir and Askari |\n";
        cout << "     |_________________________|\n";
        cout << "\033[0m"; // Reset color

        Sleep(4000);
        cout << endl;
        cout << "\033[36m"; // ANSI_CYAN
        cout << "1. Sign Up\n2. Sign In\n3. Exit\n";
        cout << "\033[0m"; // Reset color
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();            
            cin.ignore(); // Discard invalid input
            cout << "Error: Please enter a valid integer.\n";
            continue; // Go back to the beginning of the loop
        }

        // Check if the choice is within the valid range
        if (choice < 1 || choice > 3) {
            cout << "Error: Invalid choice. Please enter a number between 1 and 3.\n";
            continue; // Go back to the beginning of the loop
        }

        return choice; // Return the valid choice
    }
}

int main() {
    int userChoice = display();


    return 0;
}
