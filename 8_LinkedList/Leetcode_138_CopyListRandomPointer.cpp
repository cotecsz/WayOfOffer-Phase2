//
// Created by dream on 2020/12/6.
//

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)    return nullptr;

        Node* cur = head;
        while (cur){
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        cur = head;
        while (cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        Node* newHead = head->next;
        Node* pre = head;
        cur = head->next;
        while (cur->next){
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;

        return newHead;
    }
};