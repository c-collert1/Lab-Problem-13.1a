#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

void pressEnterToContinue();
void countAlphabetFrequency(string& filename, double letterFreq[]);

int main() {
    
    double letterFreq[26] = {};
    double totalLetters = 0;

    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    countAlphabetFrequency(filename, letterFreq);
    for (int i = 0;i < 26;i++) {
        totalLetters += letterFreq[i];
    }
    cout << "Total letters: " << totalLetters << endl;
    cout << "Alphabet Letter Frequency:\n";
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        cout << letter << ": " << (letterFreq[letter - 'a'] / totalLetters)*100 << "%" << endl;
    }

    pressEnterToContinue();
    return 0;
}

void pressEnterToContinue() {
    cout << "Press Enter to continue...";
    cin.ignore(1024, '\n');
    cin.get(); 
}

void countAlphabetFrequency(string& filename, double letterFreq[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
    }

    char characterCount;
    while (file.get(characterCount)) {
        if (isalpha(characterCount)) { 
            characterCount = tolower(characterCount); 
            letterFreq[characterCount - 'a']++; 
        }
    }

    file.close();
}
