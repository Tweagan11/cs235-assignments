#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    ~DLList() {}

    const Node* get_head() const {
        // implement get_head here
        return m_head;
    }

    void push_front(T item) {
        // implement push_front here
        Node * ptr = new Node(item);
        if (m_head != nullptr) {
            m_head->prev = ptr;
            ptr->next = m_head;
        }
        m_head = ptr;
        m_size++;
    }
    void push_back(T item) {
        // implement push_back here
        Node * ptr = new Node(item);
        if (m_tail != nullptr){
            m_tail->next = ptr;
            ptr->prev = m_tail;
        }
        m_tail = ptr;
        m_size++;
    }
    void insert(T item, int position) {
        // implement insert here
//        if (position == 0){
//            push_front(item);
//            return;
//        }
//        if (position == m_size - 1 || position >= m_size){
//            push_back(item);
//            return;
//        }

        Node * pos_ptr = m_head;
        Node * ptr = new Node(item);
        int i = 0;
        while(i <= position) {
            if (pos_ptr != NULL && pos_ptr->next != nullptr) {
                pos_ptr = pos_ptr->next;
            }

            i++;
        }
        if (pos_ptr == NULL){
            pos_ptr = ptr;
        }
        else{
            if (pos_ptr->prev != NULL){
                ptr->prev = pos_ptr->prev;
                pos_ptr->prev->next = ptr;
            }
            ptr->next = pos_ptr;
            pos_ptr->prev = ptr;
        }

    }

    void pop_front() {
        // implement pop_front here
    }
    void pop_back() {
        // implement pop_back here
    }
    void remove(int position) {
        // implement remove here
    }

    const T& front() const {
        // implement front here
    }
    const T& back() const {
        // implement back here
    }
    const T& at(int index) const {
        // implement at here
    }

    bool contains(const T& item) const {
        // implement contains here
    }

    int size() const {
        // implement size here
        return m_size;
    }

    void clear() {
        // implement clear here
    }

private:
    Node * m_head;
    Node * m_tail;
    size_t m_size;

};
