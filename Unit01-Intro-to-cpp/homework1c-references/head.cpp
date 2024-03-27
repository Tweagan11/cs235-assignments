#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

void readLines (int n = 10, const string& file = "") {
    string currLine;
    if (file == "") {
        for (int i = 0; i < n; i++) {
            getline(cin,currLine);
            cout << currLine << endl;
        }
    } else {
        ifstream input(file);
        string line;
        if (input.is_open()){
            for (int i = 0; i < n; i++)
                if (!input.eof()) {
                    getline(input,line);
                    cout << line << endl;
                } else {
                    break;
                }
        }
        input.close();
    }
}

void readLines(const string& file) {
    ifstream input(file);
    string line;
    int n = 10;
    if (input.is_open()){
        for (int i = 0; i < n; i++)
            if (!input.eof()) {
                getline(input,line);
                cout << line << endl;
            } else {
                break;
            }
        input.close();
    } else {
        cerr << "Unable to open file: " << file << endl;
    }

}

int main(int argc, char const* argv[]) {
    string filename;

    if (argc == 1) {
        readLines();
    } else if (argc == 2) {
        try {
            int n = abs(stoi(argv[1]));
            readLines(n);
        } catch (invalid_argument const& e) {
            filename = argv[1];
            readLines(filename);
        }
    } else if (argc == 3){
        try {
            int n = abs(stoi(argv[1]));
            filename = argv[2];
            readLines(n, filename);
        } catch (invalid_argument const& e) {
            int n = abs(stoi(argv[2]));
            filename = argv[1];
            readLines(n, filename);
        }
    } else {
        cerr << "Too many arguments, please use two." << endl;
    }


    return 0;
}
