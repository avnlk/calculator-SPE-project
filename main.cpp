#include <iostream>
#include "calculator.h"

void show_menu() {
    std::cout << "Select operation:" << std::endl;
    std::cout << "1. Square Root" << std::endl;
    std::cout << "2. Factorial" << std::endl;
    std::cout << "3. Natural Logarithm" << std::endl;
    std::cout << "4. Power" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        show_menu();
        std::cout << "Enter choice(1-5): ";
        if (!(std::cin >> choice)) {
            break;
        }

        switch (choice) {
            case 1: {
                std::cout << "Enter a number: ";
                std::cin >> num1;
                if (num1 < 0) {
                    std::cout << "Invalid input, number must be non-negative." << std::endl;
                } else {
                    std::cout << "Square root of " << num1 << " is " << calculate_square_root(num1) << std::endl;
                }
                break;
            }
            case 2: {
                int n;
                std::cout << "Enter a non-negative integer: ";
                std::cin >> n;
                if (n < 0) {
                    std::cout << "Invalid input, number must be non-negative." << std::endl;
                } else {
                    std::cout << "Factorial of " << n << " is " << calculate_factorial(n) << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Enter a number: ";
                std::cin >> num1;
                if (num1 <= 0) {
                    std::cout << "Invalid input, number must be positive." << std::endl;
                } else {
                    std::cout << "Natural logarithm of " << num1 << " is " << calculate_natural_log(num1) << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "Enter base: ";
                std::cin >> num1;
                std::cout << "Enter exponent: ";
                std::cin >> num2;
                std::cout << num1 << " raised to the power of " << num2 << " is " << calculate_power(num1, num2) << std::endl;
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
