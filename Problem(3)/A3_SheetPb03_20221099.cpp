
// File name:A3_SheetPb03_20221099
// Purpose:Freq_table for the number of words in a file.
// Author(s):Abdulrahman Mohammed         
// ID(s):20221099
// Section:S5
// Date:5/12/2023
#include <bits/stdc++.h>
using namespace std;
//Returns True if it is a punc excluding the '-'
bool is_punc(char c) {
    return ispunct(c) && c != '-';
}
//Returns true if it is alpha numeric including '-'
bool is_alphanumeric(char c) {
    return isalnum(c) || c == '-';
}

void toLowerCase(string& str) {
    for (char& c : str) {
        c = tolower(c);
    }
}

void createFrequencyTable(string fileName) {
    map<string, int> frequencyTable;
    string word;

    ifstream file(fileName);

    while (file >> word) {
        // Clean the word of punc and non alphanumeric characters
        string cleanWord;
        for (char c : word) {
            if (is_alphanumeric(c) and !is_punc(c)) {
                cleanWord += c;
            }
        }

        toLowerCase(cleanWord);

        if (!cleanWord.empty()) {
            frequencyTable[cleanWord]++;
        }
    }

    file.close();

    //Output
    for (pair<string, int> pair : frequencyTable) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string fileName;

    cout << "enter the file name: ";
    cin >> fileName;

    createFrequencyTable(fileName);

}