//
// Created by dream on 2020/11/27.
//

class MyLinkedList {
public:

    // 链表节点定义
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val): val(val), next(nullptr){}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        _size = 0;
        _dummyHead = new ListNode(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index > _size - 1){
            return -1;
        }
        ListNode* node = _dummyHead;
        for (int i = 0; i <= index; i++){
            node = node->next;
        }
        return node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        ListNode* node = _dummyHead;
        while (node->next){
            node = node->next;
        }
        node->next = newNode;
        _size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > _size){
            return ;
        }

        ListNode* newNode = new ListNode(val);
        ListNode* node = _dummyHead;
        while (index--){
            node = node->next;
        }
        newNode->next = node->next;
        node->next = newNode;
        _size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0){
            return ;
        }
        ListNode* cur = _dummyHead;
        while (index--){
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        --_size;
    }

private:
    int _size;
    ListNode* _dummyHead;
};

int main(){

    return 0;
}