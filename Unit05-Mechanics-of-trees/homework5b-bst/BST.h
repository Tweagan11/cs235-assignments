#pragma once
#include <stack>
using namespace std;

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() {
        // implement the contructor here
        root = nullptr;
        m_size = 0;
    }

    ~BST() {
        // implement the destructor here
        clear();
        delete root;
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
        return root;
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
        Node* node = new Node(item);
        if (m_size == 0){
            root=node;
            m_size++;
            return true;
        }
        bool isAdded = addToNode(root, node);
        if(isAdded){
            m_size++;
            return true;
        } else{
            delete node;
            return false;
        }
    }

    bool addToNode(Node* root_node, Node* new_node){
        if(new_node->value == root_node->value){
            return false;
        }
        if(new_node->value < root_node->value){
            if(root_node->left == nullptr){
                root_node->left = new_node;
                return true;
            } else {
                return addToNode(root_node->left, new_node);
            }
        } else {
            if(root_node->right == nullptr){
                root_node->right = new_node;
                return true;
            } else {
                return addToNode(root_node->right, new_node);
            }
        }
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
        if(m_size == 0){
            return false;
        }
        bool isRemoved = remove_helper(root, item);
        if(isRemoved){
            m_size--;
            return true;
        } else{
            return false;
        }
    }

    Node* inorder_predecessor(Node* root_node){
        Node* iop = root_node->left;
        while (iop->right != nullptr){
            iop = iop->right;
        }
        return iop;
    }

    bool remove_helper(Node*& node, T value){
        if (node == nullptr){
            return false;
        }
        if (node->value == value){
            if(node->left == nullptr){
                node = node->right;
            } else if (node->right == nullptr){
                node = node->left;
            } else {
                Node* iop = inorder_predecessor(node);
                node->value = iop->value;
                remove_helper(node->left, iop->value);
            }
            return true;
        } else if (value < node->value){
            return remove_helper(node->left, value);
        } else {
            return remove_helper(node->right, value);
        }
    }

    bool contains(T item) const {
        // implement contains here
        Node* ptr = root;
        while (ptr != nullptr){
            if (ptr->value == item){
                return true;
            }
            else if (item < ptr->value){
                ptr = ptr->left;
            }else {
                ptr = ptr->right;
            }
        }
        return false;
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
        clear_helper(root);
    }

    void clear_helper(Node*& node){
        if(node == nullptr){
            return;
        }
        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
        node = nullptr;
        m_size--;
    }



    int size() const {
        // implement size here
        return m_size;
    }
private:
    size_t m_size;
    Node* root;

};
