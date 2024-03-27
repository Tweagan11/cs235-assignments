#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char const* argv[]) {
    vector<string> unique;
    string input;

    if (argc == 1){
        while(getline(cin, input)) {
            if (input.empty()) {
                break;
            }
            bool check = true;
            for(int i = 0; i < unique.size(); i++){
                if (unique.at(i) == input) {
                    check = false;
                }
            }
            if (check) {
                unique.push_back(input);
            }
        }
    } else if (argc == 2) {
        ifstream infile;
        infile.open(argv[1]);
        if (infile.is_open()) {
            while (getline(infile, input)){
                bool check = true;

                for(int i = 0; i < unique.size(); i++){
                    if (unique.at(i) == input) {
                        check = false;
                    }
                }
                if (check) {
                    unique.push_back(input);
                }
            }
        } else {
            cerr << "cannot open file." << endl;
        }
    }

    for (int i = 0; i < unique.size(); i++) {
        cout << unique.at(i) << endl;
    }

    return 0;
}
