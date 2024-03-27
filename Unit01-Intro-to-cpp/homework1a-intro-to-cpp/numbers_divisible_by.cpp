#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const* argv[]) {

    int a = stoi(argv[1]);
    int b = stoi(argv[2]);
    int c = stoi(argv[3]);

    if (a>=b){
        while(a>=b) {
            if (a % c == 0){
                cout << a << endl;
            }
            a = a-1;
        }
    } else if (a <= b) {
        while(a<=b) {
            if (a % c == 0){
                cout << a << endl;
            }
            a = a+1;
        }
    }

    return 0;
}
