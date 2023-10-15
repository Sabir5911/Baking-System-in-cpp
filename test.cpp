#include <fstream>
#include <string>
#include <iostream>

using namespace std;
#include <chrono>
#include <thread>


// int CashDeposit() {
//     int Balance = 0; // Initialize balance to 0

//     while (true) {
//         int choices;
//         std::cout << "1. Deposit\n2. Quit\n";
//         std::cin >> choices;

//         if (choices == 1) {
//             int Cash = 0;
//             std::cout << "Enter the amount you want to deposit: ";
//             std::cin >> Cash;

//             Balance += Cash; // Add the deposited cash to the balance

//     };
//     cout<<Balance;
//     return Balance; // Return the final balance
// }
// }
// int main() {

//      int finalBalance = CashDeposit();
//     std::cout << "Final Balance: " << finalBalance << std::endl;
//     return 0;

// }


// #include <iostream>

// int CashDeposit() {
//     int Balance = 0; // Initialize balance to 0

//     while (true) {
//         int choices;
//         std::cout << "1. Deposit\n2. Quit\n";
//         std::cin >> choices;

//         if (choices == 1) {
//             int Cash = 0;
//             std::cout << "Enter the amount you want to deposit: ";
//             std::cin >> Cash;

//             Balance += Cash; // Add the deposited cash to the balance

//             std::cout << "Your balance has been updated." << std::endl;
//             std::cout << "Your current balance is: " << Balance << std::endl;
//         } else if (choices == 2) {
//             break; // Quit the loop
//         } else {
//             std::cout << "Invalid choice. Please enter 1 to deposit or 2 to quit." << std::endl;
//         }
//     }
//     return Balance; // Return the final balance
// }

// int main() {
//     char tryAgain;
    
//     do {
//         int finalBalance = CashDeposit();
//         std::cout << "Final Balance: " << finalBalance << std::endl;

//         std::cout << "Do you want to try again? (y/n): ";
//         std::cin >> tryAgain;
//     } while (tryAgain == 'y' || tryAgain == 'Y');
    
//     return 0;
// }

