#include <fstream>
#include <string>
#include <iostream>
using namespace std;

bool isValidHtml(string filePath) 
{
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open the file." << endl;
        return false;
    }

    int openTagCount = 0, closeTagCount = 0;
    char symbol;
    bool tagOpened = false;

    while (inputFile.get(symbol)) {
        if (symbol == '<') {
            tagOpened = true;
            openTagCount++;
        }
        else if (symbol == '>') {
            if (tagOpened)
            {
                closeTagCount++;
                tagOpened = false;
            }
        }
    }

    inputFile.close();

    if (openTagCount == closeTagCount) {
        return true;
    }
    else {
        cout << "Error: The HTML tags are not balanced." << endl;
        return false;
    }
}

int main()
{
    string filePath;
    cout << "Enter path to file: ";
    cin >> filePath;

    if (isValidHtml(filePath)) cout << "File has been validated." << endl;
    else cout << "File doesn't validated." << endl;

    return 0;
}