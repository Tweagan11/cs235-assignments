#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char const* argv[]) {
    if(argc < 3) {
        cerr << "Missing required files." << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    if (!infile.is_open() || !outfile.is_open()) {
        throw invalid_argument("Unable to open files.");
    }
    string firstName;
    string lastName;
    int score = 0;
    double mul = 1;

    while(infile >> firstName >> lastName >> score >> mul){
        outfile << lastName << ", " << firstName << ": " << score * mul << endl;
    }

//    while(!infile.eof()){
//        infile >> firstName;
//        infile >> lastName;
//        infile >> score;
//        infile >> mul;
//        outfile << lastName << ", " << firstName << ": " << score * mul << endl;
//    }




    return 0;
}
