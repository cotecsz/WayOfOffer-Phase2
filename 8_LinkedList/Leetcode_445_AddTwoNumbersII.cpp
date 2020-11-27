//
// Created by dream on 2020/11/27.
//

#include "LinkedList.h"
#include <stack>
using namespace std;


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> st1;
        stack<int> st2;

        while (l1 != nullptr){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr){
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* cur = nullptr;
        int carry = 0;
        while (!st1.empty() || !st2.empty() || carry > 0){
            int x = 0, y = 0;
            if (!st1.empty()){
                x = st1.top();
                st1.pop();
            }

            if (!st2.empty()){
                y = st2.top();
                st2.pop();
            }

            int sum = x + y + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = cur;
            cur = node;
        }

        return cur;
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