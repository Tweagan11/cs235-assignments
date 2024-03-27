#include <iostream>
#include <string>
using namespace std;

void sort(std::string& a, std::string& b, std::string& c) {
    string copy;
    if (a > b || a > c){
        if (a > b) {
            copy = a;
            a = b;
            b = copy;
        }
        if (a > c) {
            copy = a;
            a = c;
            c = copy;
        }
    }
    if (b > c) {
        copy = b;
        b = c;
        c = copy;
    }

}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
