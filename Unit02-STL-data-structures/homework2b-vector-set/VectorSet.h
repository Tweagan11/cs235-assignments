#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class VectorSet {
private:
    vector<T> my_vec;
public:

//    VectorSet() {};

    bool contains(T item) const {
        for(int i = 0; i < my_vec.size(); i++){
            if (my_vec[i] == item){
                return true;
            }
        }
        return false;
    }

    bool insert(T item) {
        if (contains(item)) {
            return false;
        } else {
            my_vec.push_back(item);
            return true;
        }
    }

    bool remove(T item) {
        // implement remove here
        for (auto iter = my_vec.begin(); iter != my_vec.end(); iter++){
            if (*iter == item) {
                my_vec.erase(iter);
                return true;
            }
        }
        return false;
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return my_vec.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        return my_vec.empty();
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        my_vec.clear();
        // remove all items from the set
    }
};
