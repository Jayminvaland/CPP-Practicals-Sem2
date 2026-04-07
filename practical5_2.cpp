#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Error opening file\n";
        return 0;
    }

    string line;
    int charCount = 0, wordCount = 0, lineCount = 0;

    while (getline(file, line)) {
        lineCount++;

        bool inWord = false;

        for (int i = 0; i < line.length(); i++) {
            charCount++;

            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    file.close();
    return 0;
}