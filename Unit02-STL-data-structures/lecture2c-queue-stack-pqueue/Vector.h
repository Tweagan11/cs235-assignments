//
// Created by Teagan Smith on 2/1/24.
//

#ifndef LECTURE2C_QUEUE_STACK_PQUEUE_VECTOR_H
#define LECTURE2C_QUEUE_STACK_PQUEUE_VECTOR_H

#include <vector>
using namespace std;

template <class T>
class Stack {
private:
    vector<T> m_data;

public:
    size_t size() {
        return m_data.size();
    }
    bool empty() {
        return m_data.empty();
    }
    void push(const T& item){
        m_data.push_back(item);
    }
    void pop(){
        m_data.pop_back();
    }
    T& top() {
        return m_data.at(m_data.size()-1);
    }
    const T& top(){
        return m_data.at(m_data.size()-1);
    }

};



#endif //LECTURE2C_QUEUE_STACK_PQUEUE_VECTOR_H
