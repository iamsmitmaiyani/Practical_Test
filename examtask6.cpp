#include <iostream>
#include <stdexcept> // For std::runtime_error

class MathOperations {
public:
    // Method to perform division operation
    double divide(double numerator, double denominator) {
        if (denominator == 0) {
            throw std::runtime_error("Error: Division by zero is not allowed.");
        }
        return numerator / denominator;
    }
};

int main() {
    MathOperations mathOps;
    double num, denom;

    // Prompt user for input
    std::cout << "Enter numerator: ";
    std::cin >> num;
    
    std::cout << "Enter denominator: ";
    std::cin >> denom;

    try {
        // Attempt to perform division
        double result = mathOps.divide(num, denom);
        std::cout << "Result of division: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        // Handle division by zero or other runtime errors
        std::cerr << e.what() << std::endl;
    } catch (...) {
        // Handle any other unexpected errors
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    return 0;
}
