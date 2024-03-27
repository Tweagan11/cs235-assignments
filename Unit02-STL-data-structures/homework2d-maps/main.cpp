#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <list>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]){
    vector<string> tokens;
    set<string> unique;
    string filename = argv[1];
    string next_line;  // Each data line
    ifstream in(filename);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
            // cout << token<<endl;
        }
    }

    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    ofstream out_set(filename + "_set.txt");
    for(set<string>::iterator it=unique.begin(); it!=unique.end(); ++it)
        out_set << ' ' << *it;
    out_set.close();

    ofstream out_vector(filename + "_vector.txt");
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it)
        out_vector << ' ' << *it;
    out_vector.close();


    map<string, string> wordmap;
    string last="";
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[last]=*it;
        last = *it;
    }

    ofstream out_map(filename + "_map.txt");
    for (map<string, string>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it) {
        out_map << it->first << ", " << it->second << endl;
    }
    out_map.close();

    string state = "";
    for(int i = 0; i < 100; i++){
        cout << wordmap[state] << " ";
        state = wordmap[state];
    }
    cout << endl;

    map<string, vector<string> > wordmap_2;
    string state2 = "";
    for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
        wordmap_2[state2].push_back(*it);
        state2 = *it;
    }

    srand(time(NULL)); // this line initializes the random number generated
    // so you don't get the same thing every time
    state = "";
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap_2[state].size();
        cout << wordmap_2[state][ind] << " ";
        state = wordmap_2[state][ind];
    }
    cout << endl;

    map<list<string>, vector<string> > wordmap_3;
    list<string> state_3;
    int M=4;
    for (int i = 0; i < M; i++) {
        state_3.push_back("");
    }

    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap_3[state_3].push_back(*it);
        state_3.push_back(*it);
        state_3.pop_front();
    }

    state_3.clear();
    for (int i = 0; i < M; i++) {
        state_3.push_back("");
    }

    srand(time(NULL));
    for (int i = 0; i < 150; i++) {
        int ind = rand() % wordmap_3[state_3].size();
        if (isupper(wordmap_3[state_3][ind][0]) && i!= 0){
            int punc = rand() % 8;
            if (punc == 0){
                cout << ". ";
            } else if (punc == 1){
                cout << ", ";
            } else if (punc == 3) {
                cout << "! ";
            } else if (punc == 5) {
                cout << "? ";
            } else {
                cout << " ";
            }
            }
        else {
            cout << " ";
        }
        cout << wordmap_3[state_3][ind];
        state_3.push_back(wordmap_3[state_3][ind]);
        state_3.pop_front();
    }

}