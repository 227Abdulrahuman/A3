// File name:A3_SheetPb02_20220206
// Purpose: Document Similarity create a C++ class, 'StringSet', for managing sets of strings, performing set operations, and calculating document similarity through the binary cosine coefficient.
// Author(s):Abdelmonaem Mahmoud
// ID(s):20220206
// Section:S5
// Date:5/12/2023
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class StringSet {
    unordered_set<string> strings;
public:
    // Default constructor
    StringSet() {}

    // Constructor that takes a file name and loads the words
    StringSet(const string& fileName) {
        ifstream file(fileName);

        string word;
        while (file >> word)
        {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            addString(word);
        }
    }

    // Constructor that takes a string and breaks it into tokens
    StringSet(const string inputString, int n) {
        istringstream iss(inputString);
        string word;
        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            addString(word);
        }
    }

    // Add a string to the set
    void addString(string s) {
        strings.insert(s);
    }

    // Remove a string from the set
    void removeString(string s) {
        strings.erase(s);
    }

    // Clear the entire set
    void clearSet() {
        strings.clear();
    }

    // Return the number of strings in the set
    size_t size() {
        return strings.size();
    }

    // Output all strings in the set
    void display() {
        cout << "StringSet Contents: ";
        for (string str : strings) {
            cout << str << " ";
        }
        cout << endl;
    }

    // Overload the + operator to return the union of two StringSet objects
    StringSet operator+(StringSet other) {
        StringSet result = *this;
        for (string str : other.strings) {
            result.addString(str);
        }
        return result;
    }

    // Overload the * operator to return the intersection of two StringSet objects
    StringSet operator*(StringSet other) {
        StringSet z;
        for (const auto& str : strings) {
            if (other.contains(str)) {
                z.addString(str);
            }
        }
        return z;
    }

    bool contains(string s) {
        return strings.find(s) != strings.end();
    }

    double computeSimilarity(StringSet other) {
        unordered_set<string> intersectionSet;
        for (string str : strings) {
            if (other.contains(str)) {
                intersectionSet.insert(str);
            }
        }

        double intersectionSize = intersectionSet.size();
        double qSize = strings.size();
        double dSize = other.size();

        if (intersectionSize == 0 || qSize == 0 || dSize == 0) {
            return 0.0; // Avoid division by zero
        }

        double similarity = intersectionSize / (sqrt(qSize) * sqrt(dSize));
        return similarity;
    }
};

int main() {
    // Test with a file
    StringSet setFromFile("abdo.txt");
    cout << "Set from file:" << endl;
    setFromFile.display();

    // Test with a string
    StringSet setFromString("This is a sample string.", 1);
    cout << "Set from string:" << endl;
    setFromString.display();

    // Test addString
    setFromFile.addString("newword");
    cout << "After adding 'newword'." << endl;
    setFromFile.display();

    // Test removeString
    setFromFile.removeString("example");
    cout << "After removing 'example'." << endl;
    setFromFile.display();

    // Test clearSet
    setFromFile.clearSet();
    cout << "After clearing the set." << endl;
    setFromFile.display();
    cout << "Number of elements after clearing: " << setFromFile.size() << endl;

    // Test union
    StringSet unionSet = setFromFile + setFromString;
    cout << "Union of two sets." << endl;
    unionSet.display();

    // Test intersection
    StringSet intersectionSet = setFromFile * setFromString;
    cout << "Intersection of two sets." << endl;
    intersectionSet.display();

    StringSet documentSet("abdo.txt");
    cout << "Document Set:" << endl;
    documentSet.display();

    // Test with a query
    StringSet querySet("abdo2.txt");
    cout << "Query Set:" << endl;
    querySet.display();

    // Test computeSimilarity
    double similarity = documentSet.computeSimilarity(querySet);

    cout << "Similarity between Document and Query: " << similarity << endl;

    return 0;
}
