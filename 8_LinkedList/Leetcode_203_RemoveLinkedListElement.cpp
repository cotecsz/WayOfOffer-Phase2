//
// Created by dream on 2020/11/27.
//

#include "LinkedList.h"
#include <vector>
using namespace std;

/*
 * Leetcode203 删除链表节点
 *      区分头结点与后续节点。
 *      删除头结点：直接删除，head 指向下一个节点
 *      后续节点：  每次判断下一个节点是否为删除节点，如果是删除，否则cur = cur->next
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode* cur = head;
        while (cur && cur->next){
            if (cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        return head;
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

    Solution sol;
    ListNode* headRes = sol.removeElements(&head, 1);
    return 0;
}
