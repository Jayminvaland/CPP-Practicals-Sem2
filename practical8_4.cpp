#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
int main() {
    std::string filePath;
    std::ifstream file;

    while (true) {
        std::cout << "Enter file path (or 'exit' to quit): ";
        std::cin >> filePath;

        if (filePath == "exit") return 0;

        file.open(filePath);
        if (file.is_open()) {
            break;
        } else {
            std::cerr << "Error: Could not open file. Please check the path and try again." << std::endl;
        }
    }

    std::string line;
    int lineCount = 0;
    double sum = 0;
    int validEntries = 0;

    std::cout << "\n--- Processing File Data ---\n";

    while (std::getline(file, line)) {
        lineCount++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        double value;

        if (ss >> value) {
            sum += value;
            validEntries++;
            std::cout << "Line " << lineCount << ": Processed value " << value << std::endl;
        } else {
            std::cerr << "Line " << lineCount << ": Skipping corrupted data [ " << line << " ]" << std::endl;
        }
    }

    std::cout << "\n--- Summary Report ---\n";
    std::cout << "Total lines read: " << lineCount << std::endl;
    std::cout << "Valid numeric entries: " << validEntries << std::endl;
    
    if (validEntries > 0) {
        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Average: " << sum / validEntries << std::endl;
    } else {
        std::cout << "No valid numeric data found to calculate average." << std::endl;
    }

    file.close();
    return 0;
}