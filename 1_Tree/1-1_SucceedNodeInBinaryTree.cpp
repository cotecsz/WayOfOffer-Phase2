//
// Created by dream on 2020/12/7.
//

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int val): val(val), left(nullptr), right(nullptr), parent(nullptr){}
};


class Solution{
public:
    TreeNode* findSucceedNode(TreeNode* node){
        if (node == nullptr)    return nullptr;

        TreeNode* succeedNode = nullptr;
        if (node->right != nullptr){
            succeedNode = findMostLeft(node->right);
        }
        else{
            succeedNode = node->parent;
            while (succeedNode != nullptr && node != succeedNode->left){
                node = succeedNode;
                succeedNode = node->parent;
            }
        }

        return succeedNode;
    }

private:
    TreeNode* findMostLeft(TreeNode* node){
        if (node->left == nullptr)    return nullptr;

        while (node->left){
            node = node->left;
        }

        return node;
    }
};


int main(){

    TreeNode a(0);
    TreeNode b(1);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(5);
    TreeNode g(6);

    a.left = &b;
    a.right = &c;

    b.parent = &a;
    c.parent = &a;

    b.left = &d;
//    b.right = &e;

    d.parent = &b;
//    e.parent = &b;

     c.left = &f;
//    c.right = &g;

    f.parent = &c;
//    g.parent = &c;


    Solution sol;
    TreeNode* node = sol.findSucceedNode(&b);
    cout << node->val << endl;

    return 0;
}