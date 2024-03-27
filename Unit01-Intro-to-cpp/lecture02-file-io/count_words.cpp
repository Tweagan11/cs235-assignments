#include <iostream>
using std::cout, std::cerr, std::endl;

#include <string>
using std::string;

#include <fstream>
#include <stdexcept>
using namespace std;

int count_words(string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw invalid_argument("Unable to open " + filename);
    }

    int count = 0;
    string word;
    while (file >> word) {
        count++;
    }

    file.close();
    
    return count;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cerr << "Missing required argument: filename" << endl;
        return 1;
    }

    string filename = argv[1];
    try {
        int counts = count_words(filename);
        cout << "Word count: " << counts << endl;
        return 0;

    } catch (invalid_argument ex) {
        cerr << ex.what() << endl;
        return 1;
    }
}