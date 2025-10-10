#include <iostream>
#include <limits>
#include "sqrt_func.h"
#include "factorial_func.h"
#include "ln_func.h"
#include "power_func.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int choice;
    while (true) {
        std::cout << "\n=== Scientific Calculator ===\n";
        std::cout << "1. Square Root (√x)\n";
        std::cout << "2. Factorial (x!)\n";
        std::cout << "3. Natural Logarithm (ln x)\n";
        std::cout << "4. Power (x^b)\n";
        std::cout << "5. Exit\n";
        std::cout << "Select option: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 5) {
            std::cout << "Goodbye!!!\n";
            break;
        }

        double x, b;
        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter x: ";
                    std::cin >> x;
                    std::cout << "√" << x << " = " << squareRoot(x) << "\n";
                    break;
                case 2:
                    std::cout << "Enter integer n: ";
                    std::cin >> x;
                    std::cout << x << "! = " << factorial(static_cast<int>(x)) << "\n";
                    break;
                case 3:
                    std::cout << "Enter x: ";
                    std::cin >> x;
                    std::cout << "ln(" << x << ") = " << naturalLog(x) << "\n";
                    break;
                case 4:
                    std::cout << "Enter base x: ";
                    std::cin >> x;
                    std::cout << "Enter exponent b: ";
                    std::cin >> b;
                    std::cout << x << "^" << b << " = " << power(x, b) << "\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
                    break;
            }
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}

