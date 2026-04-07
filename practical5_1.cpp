#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    return s;
}

int main() {
    string paragraph;
    getline(cin, paragraph);

    string words[1000];
    int freq[1000] = {0};
    int count = 0;

    string temp = "";

    for (int i = 0; i <= paragraph.length(); i++) {
        if (paragraph[i] == ' ' || paragraph[i] == '\0') {
            if (temp != "") {
                temp = toLowerCase(temp);

                int found = -1;
                for (int j = 0; j < count; j++) {
                    if (words[j] == temp) {
                        found = j;
                        break;
                    }
                }

                if (found != -1) {
                    freq[found]++;
                } else {
                    words[count] = temp;
                    freq[count] = 1;
                    count++;
                }

                temp = "";
            }
        } else {
            temp += paragraph[i];
        }
    }

    for (int i = 0; i < count; i++) {
        cout << words[i] << " : " << freq[i] << endl;
    }

    return 0;
}