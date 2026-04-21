#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
int main() {
    std::map<std::string, std::vector<std::string>> directory;
    int choice;
    std::string folderName, fileName;

    while (true) {
        std::cout << "\n1. Add Folder\n2. Add File to Folder\n3. Display Directory\n4. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter folder name: ";
            std::cin >> folderName;
            directory[folderName]; 
        } 
        else if (choice == 2) {
            std::cout << "Enter folder name: ";
            std::cin >> folderName;
            if (directory.find(folderName) != directory.end()) {
                std::cout << "Enter file name: ";
                std::cin >> fileName;
                directory[folderName].push_back(fileName);
            } else {
                std::cout << "Folder does not exist.\n";
            }
        } 
        else if (choice == 3) {
            std::cout << "\n--- Directory Structure ---\n";
            for (auto it = directory.begin(); it != directory.end(); ++it) {
                std::cout << "[" << it->first << "]\n";
                if (it->second.empty()) {
                    std::cout << "  (Empty)\n";
                } else {
                    for (const auto& file : it->second) {
                        std::cout << "  - " << file << "\n";
                    }
                }
            }
        } 
        else if (choice == 4) {
            break;
        }
    }
    return 0;
}