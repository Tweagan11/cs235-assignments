#include <iostream>
#include <string>
using namespace std;

string input(string prompt) {
    cout << prompt;
    cout.flush();
    string response;
    getline(cin, response);
    return response;
}

int main() {
    string op = input("operation: ");
    int x;
    int y;
    while (!op.empty()){

        if (op == "add") {
            cout << "left operand: ";
            cin >> x;
            cout << "right operand: ";
            cin >> y;
            cin.ignore();
            cout << x + y << endl;
        } else if (op == "subtract") {
            cout << "left operand: ";
            cin >> x;
            cout << "right operand: ";
            cin >> y;
            cin.ignore();
            cout << x - y << endl;
        } else if (op == "multiply") {
            cout << "left operand: ";
            cin >> x;
            cout << "right operand: ";
            cin >> y;
            cin.ignore();
            cout << x * y << endl;
        } else if (op == "divide") {
            cout << "left operand: ";
            cin >> x;
            cout << "right operand: ";
            cin >> y;
            cin.ignore();
            cout << x / y << endl;
        } else if (op == "mod") {
            cout << "left operand: ";
            cin >> x;
            cout << "right operand: ";
            cin >> y;
            cin.ignore();
            cout << x % y << endl;
        } else if (!op.empty()){
            cout << op << " isn't a valid operation" << endl;
        }
        op = input("operation: ");
    }

    return 0;
}
