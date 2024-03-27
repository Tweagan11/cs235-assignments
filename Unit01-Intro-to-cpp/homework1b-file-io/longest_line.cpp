#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int line_count(string line){
    stringstream line_stream(line);
    int total = 0;
    string word;
    while (line_stream >> word){
        total += 1;
    }
    return total;
}

int main(int argc, char const* argv[]) {

    ifstream infile(argv[1]);

    string line;
    string newLine;
    while (getline(infile, line)) {
        if (line_count(line) > line_count(newLine)){
            newLine = line;
        }
    }

    cout << newLine << endl;

    return 0;
}
