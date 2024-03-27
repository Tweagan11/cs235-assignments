#include <vector>
#include <iostream>
#include <string>
using namespace std;



int main() {

    vector<string> grocery_list;
    string items;
    cout << "Enter item: ";
    while(getline(cin,items)){
        if (items.empty()) break;
        grocery_list.push_back(items);
        cout << "Enter item: ";
    }

    for (auto& item : grocery_list){
        cout << item << endl;
    }

    return 0;
}