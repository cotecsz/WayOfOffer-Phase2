//
// Created by dream on 2020/12/7.
//

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr){
            return "# ";
        }

        string res = to_string(root->val) + " ";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        queue<TreeNode*> values;
        split(data, values);

        return reconPreorder(values);
    }

private:
    void split(string res, queue<TreeNode*>& values){
        istringstream in(res);
        string value;
        while (in >> value){
            if (value == "#"){
                values.push(nullptr);
            }
            else{
                values.push(new TreeNode(stoi(value)));
            }
        }
    }

    TreeNode* reconPreorder(queue<TreeNode*>& values){
        TreeNode* node = values.front();    values.pop();

        if (node == nullptr){
            return nullptr;
        }

        TreeNode* head = node;
        head->left = reconPreorder(values);
        head->right = reconPreorder(values);

        return head;
    }
};

void printTree(TreeNode* head){
    if (head == nullptr)    return ;

    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = head;
    while (!st.empty() || cur != nullptr){
        if (cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }
        else{
            cur = st.top();     st.pop();
            res.push_back(cur->val);

            cur = cur->right;
        }
    }

    for (auto n : res){
        cout << n << " ";
    }
    cout << endl;

}

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
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    printTree(&a);

    Codec cod;
    string res = cod.serialize(&a);
    cout << res << endl;

    TreeNode* head = cod.deserialize(res);
    printTree(head);
    return 0;
}