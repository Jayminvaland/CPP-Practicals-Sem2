#include <iostream>
#include <limits>
#include <stdexcept>

int main() {
    try {
        int numerator, denominator;

        if (!(std::cin >> numerator)) {
            throw std::runtime_error("Invalid input: Numerator must be an integer.");
        }

        if (!(std::cin >> denominator)) {
            throw std::runtime_error("Invalid input: Denominator must be an integer.");
        }

        if (denominator == 0) {
            throw std::runtime_error("Math error: Division by zero is undefined.");
        }

        std::cout << "Result: " << static_cast<double>(numerator) / denominator << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}