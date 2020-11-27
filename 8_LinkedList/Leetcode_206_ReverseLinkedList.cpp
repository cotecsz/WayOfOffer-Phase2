//
// Created by dream on 2020/11/27.
//

/*
 * Leetcode 206 反转链表
 *      双指针法：cur 指向当前节点，pre指向当前指针的前一个节点，
 *
 */
#include "LinkedList.h"
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while (cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main(){
    ListNode head = ListNode(1);
    ListNode node1 = ListNode(2);
    ListNode node2 = ListNode(6);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);

    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    printLinkedList(&head);
    Solution sol;
    ListNode* headRes = sol.reverseList(&head);
    printLinkedList(headRes);
    return 0;
}