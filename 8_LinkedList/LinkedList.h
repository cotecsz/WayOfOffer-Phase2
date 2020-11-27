//
// Created by dream on 2020/11/27.
//

#ifndef WAYOFOFFER_PHASE2_LINKEDLIST_H
#define WAYOFOFFER_PHASE2_LINKEDLIST_H

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int val): val(val), next(nullptr) {}
};

void printLinkedList(ListNode* head){
    ListNode* cur = head;
    while (cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

#endif //WAYOFOFFER_PHASE2_LINKEDLIST_H
