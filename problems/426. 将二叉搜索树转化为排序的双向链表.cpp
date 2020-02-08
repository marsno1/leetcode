/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;

        auto p = inOrder(root);
        p.first->left = p.second;
        p.second->right = p.first;
        return p.first;
    }

    pair<Node*, Node*> inOrder(Node* root) {
        if (root == NULL) {
            return {NULL, NULL};
        }
        Node *min = root, *max = root;
        if (root->left) {
            auto p = inOrder(root->left);
            root->left = p.second;
            p.second->right = root;
            min = p.first;
        }

        if (root->right) {
            auto p = inOrder(root->right);
            root->right = p.first;
            p.first->left = root;
            max = p.second;
        }
        
        return {min, max};
    }
};