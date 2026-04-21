#include <iostream>
#include <cmath>
#include <exception>
#include <string>
class NegativeNumberException : public std::exception {
private:
    std::string message;
public:
    NegativeNumberException(double val) {
        message = "Error: Cannot calculate square root of negative number (" + std::to_string(val) + ")";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    double num;
    std::cout << "Enter a number to find its square root: ";

    try {
        if (!(std::cin >> num)) {
            std::cout << "Invalid input. Please enter a numeric value." << std::endl;
            return 1;
        }

        if (num < 0) {
            throw NegativeNumberException(num);
        }

        std::cout << "Square root: " << std::sqrt(num) << std::endl;

    } catch (const NegativeNumberException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}