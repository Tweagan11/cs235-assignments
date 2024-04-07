#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

int update_height(Node*& node){
    if (node->left == nullptr && node->right == nullptr){
        node->height = 1;
    } else if (node->left == nullptr) { // implies node->right is not nullptr
        node->height = 1 + update_height(node->right);
    } else if (node->right == nullptr) { // implies node->left is not nullptr
        node->height = 1 + update_height(node->left);
    } else { // Both children exist
        int leftHeight = update_height(node->left);
        int rightHeight = update_height(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
    return node->height;
}

void promote_left(Node*& root) {
    // implement promote_left here
    auto temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
    update_height(root);
}

void promote_right(Node*& root) {
    // implement promote_right here
    auto temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
    update_height(root);
}

void rebalance(Node*& root) {
    // implement rebalance here
    if (root->height == 1){
        return;
    }
    if (root->left == nullptr){
        if (root->right->height <= 1){
            return;
        }
        else {
            promote_right(root);
        }
    }
    if (root->right == nullptr){
        if (root->left->height <= 1){
            return;
        } else {
            promote_left(root);
        }
    }
    if(root->right->height - root->left->height > 1){
        if ((root->right->right->height - root->right->left->height) < 0){
            promote_left(root->right);
        }
        promote_right(root);
    }

    else if(root->right->height - root->left->height < -1){
        if ((root->left->right->height - root->left->left->height) > 0){
            promote_right(root->left);
        }

        promote_left(root);
    }
}
