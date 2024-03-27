#include <iostream>
#include <string>
#include <queue>
#include "input.h"
using namespace std;

int main(int argc, char const* argv[]) {
    priority_queue<string> q1;
    string name;
    string action;
    string priority;

    while(input("What do you want to do? ", action)){
        if (action == "add"){
            input("Name: ", name);
            input("Priority: ", priority);
            if (priority.size() < 2){
                priority = "0" + priority;
            }
            string in = priority + " - " + name;
            q1.push(in);
        }
        else if (action == "take"){
            if (!q1.empty()){
                cout << q1.top() << endl;
                q1.pop();
            } else{
                cout << "There are no more people in line" << endl;
            }
        } else {
            cout << action << " isn't a valid operation" << endl;
        }
    };




    return 0;
}
