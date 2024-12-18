#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

void NewLine(void) {
    cout << std::endl;
}

int termination(int t_f) {
    if (t_f == 1) {
        exit(0);
    }
    else {
        cout << "There is no termination: program will automatically close in 1 minute." << endl;
        Sleep(60000);
        exit(0);
    }
}

int main(void) {
    bool Continuetyping = true;
    string filename;
    string Usertext;
    int UserOption;
    int terminator;

    cout << "Welcome to console-notepad." << endl;
    cout << "Enter option number to choose: " << endl
        << "1. Create a new file or overwrite an existing file (Creates a file only if the file name is different from others)." << endl
        << "2. Continue writing in a file (Also creates a new file if the file is not found)." << endl
        << "3. Delete a file." << endl
        << "4. Read a file." << endl;
    cin >> UserOption;  // Read the user's choice
    cin.ignore();  // Clear the newline character from the buffer

    cout << "Enter a filename with extension: " << endl;
    getline(cin, filename);

    if (UserOption == 1) {
        ofstream fileOW(filename);
        NewLine();
        NewLine();
        if (fileOW.fail()) {
            cout << "ERROR: Creating or opening the file. Contact the developer." << endl;
            NewLine();
            NewLine();
            cout << "Do you want to exit: 1=yes 0=no (Code will not repeat until restarted)" << endl;
            cin >> terminator;
            termination(terminator);
        }
        else {
            cout << "File opened successfully." << endl;
        }
        Sleep(2300);
        system("cls");
        cout << "Enter '(EXIT)' exactly to disable writing." << endl;

        while (Continuetyping) {
            getline(cin, Usertext);
            if (Usertext == "(EXIT)") {
                Continuetyping = false;
                break;
            }
            fileOW << Usertext << endl;
        }
    }
    else if (UserOption == 2) {
        ofstream fileW(filename, ios::app);
        NewLine();
        NewLine();
        if (fileW.fail()) {
            cout << "ERROR: Opening the file " << filename << endl;
            NewLine();
            NewLine();
            cout << "Do you want to exit: 1=yes 0=no (Code will not repeat until restarted)" << endl;
            cin >> terminator;
            termination(terminator);
        }
        else {
            cout << "File opened successfully." << endl;
        }
        Sleep(2300);
        system("cls");
        cout << "Enter '(EXIT)' exactly to disable writing." << endl;

        while (Continuetyping) {
            getline(cin, Usertext);
            if (Usertext == "(EXIT)") {
                Continuetyping = false;
                break;
            }
            fileW << Usertext << endl;
        }
    }
    else if (UserOption == 4) {
        ifstream fileR(filename);
        if (fileR.fail()) {
            cout << "ERROR: Opening the file. Contact the developer." << endl;
            NewLine();
            NewLine();
            cout << "Do you want to exit: 1=yes 0=no (Code will not repeat until restarted)" << endl;
            cin >> terminator;
            termination(terminator);
        }
        else {
            cout << "File opened successfully." << endl;
        }
        Sleep(2300);
        system("cls");
        char c;
        while (fileR.get(c)) {
            cout << c;
        }
        NewLine();
        NewLine();
        cout << "Contents of the file are read." << endl;
    }
}