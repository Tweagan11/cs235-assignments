#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[]) {
    vector<string> unsorted_vars;
    string word;
    if(argc > 1){
        string filename = argv[1];
        ifstream infile;
        infile.open(filename);
        if (infile.is_open()){
            while(infile){
                getline(infile,word);
                unsorted_vars.push_back(word);
            }
            infile.close();
        }
        else {
            cerr << "Failed to open file" << endl;
            return 1;
        }
    }
    else{
        getline(cin, word);
        while (!word.empty()){
            unsorted_vars.push_back(word);
            getline(cin, word);
        }
    }


    for(int i = 1; i < unsorted_vars.size(); i++){
        int j = i;
        string item = unsorted_vars[i];
        while(j > 0 && unsorted_vars[j-1] > item){
            unsorted_vars[j] = unsorted_vars[j-1];
            j--;
        }
        unsorted_vars[j] = item;
    }
    for(auto var : unsorted_vars){
        cout << var << endl;
    }

    return 0;
}
