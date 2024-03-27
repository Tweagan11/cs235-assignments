//
// Created by Teagan Smith on 2/21/24.
//
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: program <filename>\n";
        return 1;
    }

    std::ifstream testFile(argv[1]);
    if (!testFile.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    } else {
        std::cout << "File opened successfully: " << argv[1] << "\n";
    }
    // Proceed with your file operations...

    return 0;
}