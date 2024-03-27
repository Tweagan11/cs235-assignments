#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    T copy;
    int middle = (left + right)/2;
    if (array[left] > array[middle] || array[left] > array[right]){
        if (array[left] > array[middle]){
            copy = array[left];
            array[left] = array[middle];
            array[middle] = copy;
        }
        if (array[left] > array[right]) {
            copy = array[left];
            array[left] = array[right];
            array[right] = copy;
        }
    }
    if (array[middle] > array[right]){
        copy = array[middle];
        array[middle] = array[right];
        array[right] = copy;
    }
    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int middle = medianOfThree(array, left, right);

    T pivot_value = array[middle];
    array[middle] = array[left];
    array[left] = pivot_value;

    int up = left + 1;
    int down = right;

    do {
        while(array[up] <= array[left] && up != right){
            up++;
        }
        while(array[down] > array[left] && down != left){
            down--;
        }
        if (up < down){
            T copy;
            copy = array[up];
            array[up] = array[down];
            array[down] = copy;
        }
    } while(up < down);

    T copy = array[down];
    array[down] = array[left];
    array[left] = copy;

    return down;
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right){
    if ((right - left) < 1){
        return;
    }
    int pivot = partition(array, left, right);
    sort_helper(array, left, pivot-1);
    sort_helper(array, pivot+1, right);
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    return sort_helper(array,0,array.size()-1);
}




