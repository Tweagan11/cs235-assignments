#pragma once
#include <list>
#include <functional>
#include <iostream>
#include <string>
using namespace std;

const size_t INITIAL_CAPACITY = 7;
const double MAX_FILL = 0.8;

template<class T>
class HashSet {
public:
    HashSet() {
        m_capacity = INITIAL_CAPACITY;
        m_size = 0;
        m_data = new list<T>[INITIAL_CAPACITY];
    }

    ~HashSet() {
        clear();
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the set
        if (fillFactor() >= MAX_FILL){
            grow();
        }
        size_t hashCode = hash<T>{}(item);
        size_t index = hashCode % m_capacity;
        if(m_data[index].size() != 0){
            for (auto entry : m_data[index]){
                if(entry == item) return false;
            }
        }
        m_data[index].push_front(item);
        m_size++;
        return true;
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        size_t index = hash<T>{}(item) % m_capacity;
        if (m_data[index].size() != 0) {
            for (auto entry : m_data[index]){
                if (entry == item){
                    m_data[index].remove(entry);
                    m_size--;
                    return true;
                }
            }
        }
        return false;
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the set, false otherwise
        size_t index = hash<T>{}(item) % m_capacity;
        if(m_data[index].size() != 0){
            for (auto entry : m_data[index]){
                if (entry == item) return true;
            }
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all elements from the set
        if (m_size == 0){
            return;
        }

        for (size_t i = 0; i < m_capacity; i++){
            m_data[i].clear();
        }
        m_size = 0;
//        delete [] m_data;
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return m_size;
    }
private:
    size_t m_size;
    size_t m_capacity;
    list<T>* m_data;

    double fillFactor(){
        return static_cast<double>(m_size)/m_capacity;
    }

    void grow(){
        size_t oldCapacity = m_capacity;
        m_capacity = 2 * m_capacity + 1;
        list<T>* oldData = m_data;
        m_data = new list<T>[m_capacity];
        m_size = 0;
        for (size_t i = 0; i < oldCapacity; i++){
            for (auto item : oldData[i]){
                insert(item);
            }
        }
        delete [] oldData;
    }

};
