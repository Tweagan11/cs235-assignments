#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    Node *head;
    size_t _size;

    void _push_back(Node*&node, T const &value){
        if (node == nullptr){
            node = new Node(value);
            _size++;
        } else {
            _push_back(node->next, value);
        }

    }

    void _clear(Node *&node){
        if (node == nullptr){
            return;
        }
        _clear(node->next);
        delete node;
        node = nullptr;
        _size--;
    }

    SLList() {}

    ~SLList() {}



    const Node* get_head() const {
        if (head == nullptr){
            return 0;
        }
        return head;
    }

    void push_back(T item) {
        _push_back(head, item);
    }

    void pop_back() {

        if(head == nullptr){
            return;
        }

        if(head->next == nullptr){
            delete head;
            head = nullptr;
            _size--;
            return;
        }
        Node* node_ptr = head;
        while (node_ptr->next->next != NULL){
            node_ptr = node_ptr->next;
        }
        delete node_ptr->next;
        node_ptr->next = nullptr;
        _size--;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return _size;
    }

    void clear() {
        _clear(head);
    }
};
