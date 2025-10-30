#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FindWord(string target, ifstream& OneFile, ofstream& Result) {
    string line_one;
    int num_one, num_ten;
    while(getline(OneFile, line_one)) {
        num_one = atoi(line_one.c_str());
        num_ten = atoi(target.c_str());
        if (num_one == num_ten) {
            Result << num_one << endl;
            break; // Exit the loop once a match is found
        }
    }
}

int main() {

    // User input
    string firstFileName, secondFileName;
    cout << "Please input your first file: ";
    cin >> firstFileName;
    cout << "Please input your second file: ";
    cin >> secondFileName;

    // Create and open a text file
    string resultFileName = firstFileName.substr(0, firstFileName.length()-4) + "_" + secondFileName.substr(0, secondFileName.length()-4) + "_result.txt";
    ofstream result(("./Result/" + resultFileName));
    ifstream resultFile(("./Result/" + resultFileName));

    // Open text files
    ifstream firstFile(("./Src/" + firstFileName));
    ifstream secondFile(("./Src/" + secondFileName));
    if(!firstFile.is_open() || !secondFile.is_open() || !resultFile.is_open()) {
        cout << "Error opening one of the files." << endl;
        return 1;
    }

    // Read from the text file
    result << "File 1: " << firstFileName << "\n" << "File 2: " << secondFileName << "\n\n" << "Result:" << "\n";
    string line;
    while (getline(firstFile, line)) {
        FindWord(line, secondFile, result);
        secondFile.clear(); // Reset the file stream to the beginning
        secondFile.seekg(0);
    }

    cout << "Complete";

    // Close the file
    firstFile.close();
    secondFile.close();
    resultFile.close();
    result.close();

    return 0;
}