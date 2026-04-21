#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
int main() {
    std::string sentence;
    std::map<std::string, int> wordCount;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::stringstream ss(sentence);
    std::string word;

    while (ss >> word) {
        
        std::string cleanedWord = "";
        for (char c : word) {
            if (std::isalnum(c)) {
                cleanedWord += std::tolower(c);
            }
        }
        if (!cleanedWord.empty()) {
            wordCount[cleanedWord]++;
        }
    }
    std::cout << "\nWord Frequency List (Alphabetical):" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
    return 0;
}