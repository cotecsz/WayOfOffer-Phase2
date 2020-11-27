//
// Created by dream on 2020/11/27.
//
#include "LinkedList.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;

            carry = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            cur->next = node;
            cur = cur->next;

            if (l1 != nullptr)  l1 = l1->next;
            if (l2 != nullptr)  l2 = l2->next;
        }

        return pre->next;
    }
};


int main(){
    ListNode head1 = ListNode(1);
    ListNode node1 = ListNode(7);
    ListNode head2 = ListNode(6);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);

    // 1 --> 7    6 --> 3 ---> 4
    head1.next = &node1;
    node1.next = nullptr;
    head2.next = &node3;
    node3.next = &node4;

    printLinkedList(&head1);
    printLinkedList(&head2);

    Solution sol;
    ListNode* headRes = sol.addTwoNumbers(&head1, &head2);
    printLinkedList(headRes);
    return 0;
}