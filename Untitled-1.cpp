#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

bool isPunctuation(char);
int lexicalAnalysis(const string&, const string&);

int main() {
    string inFile, outFile;
    //Retrieve input file name
    cout << "Enter the input source code file with directory: ";
    cin >> inFile;
    //Retrieve output file name
    cout << "Enter the output file name: ";
    cin >> outFile;

    int result = lexicalAnalysis(inFile, outFile);

    if (result == 0) {
        cout << "Lexical analysis completed successfully." << endl;
    }
    else {
        cout << "An error occurred during lexical analysis." << endl;
    }

    return result;
}
// Function to check punctuation marks
bool isPunctuation(char ch) {
    return ispunct(ch);
}

// Function to extract characters from a file and save them to output file
int lexicalAnalysis(const string& inputFile, const string& outputFile) {
    ifstream fileIn(inputFile);
    ofstream fileOut(outputFile);

    if (!fileIn.is_open() || !fileOut.is_open()) {
        cerr << "Error" << endl;
        return -1;
    }

    string word;
    char ch;

    while (fileIn.get(ch)) {

        if (isalnum(ch)) {
            word += ch;
        }
        else {
            // If we have collected a word, write it to the output file
            if (!word.empty()) {
                fileOut << " " << word;
                word.clear();  // Reset word for the next one
            }

            // If it's a punctuation mark, write it separately
            if (isPunctuation(ch)) {
                fileOut << ch;
            }
        }
    }

    fileIn.close();
    fileOut.close();
    return 0;
}

