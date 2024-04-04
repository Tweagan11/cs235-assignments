#pragma once

#include <iostream>
#include <string>
const int INITIAL_CAPACITY = 10;

template<class T>
class Vector {
public:
    Vector() {
        m_data = new T[INITIAL_CAPACITY];
        m_capacity = INITIAL_CAPACITY;
        m_size = 0;
    }

    ~Vector() {
        clear();
        delete [] m_data;
    }

    void grow(){
        size_t newSize = m_capacity * 2;
        T * newArray = new T[newSize];
        for (size_t i = 0; i < m_size; i++){
            newArray[i] = m_data[i];
        }
        delete [] m_data;
        m_data = newArray;
        m_capacity = newSize;
    }

    void push_back(T item) {
//        if(m_size < m_capacity){
//            m_data[m_size] = item;
//            m_size++;
//        } else {
//            grow();
//            m_data[m_size] = item;
//            m_size++;
//        }
        if (m_size == m_capacity){
            grow();
        }
        m_data[m_size] = item;
        m_size++;
    }

    void pop_back(){
        m_size--;
    }

    void insert(T item, int position) {
        // implement insert here
        if(position >= m_size){
            push_back(item);
        }
        else{
            if(m_size == m_capacity){
                grow();
            }
            for(int i = m_size; i >= position; i--){
                m_data[i+1] = m_data[i];
            }
            m_data[position] = item;
            m_size++;
        }
    }

    void remove(int position) {
        // implement remove here
        for(int i = position; i < m_size; i++) {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
    }


    T& operator[](int index) {
        // implement operator[] here
        if (index < 0 || index >= m_size){
            throw std::out_of_range("Index out of bounds.");
        }
        return m_data[index];
    }

    int size() const {
        return m_size;
    }

    void clear() {
        // implement clear here
    }
private:

    T * m_data;
    size_t m_capacity;
    size_t m_size;

};
