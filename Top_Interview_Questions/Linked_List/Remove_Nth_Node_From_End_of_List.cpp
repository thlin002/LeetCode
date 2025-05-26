/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}   
 };

// Given the head of a linked list, remove the nth node from the end of the list and return its head.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Two pointers approach
        // Move the first pointer n steps ahead
        ListNode *peekPtr = head;
        ListNode *ptr = head;
        for(int i = 0; i < n; ++i) {
            peekPtr = peekPtr->next;
        }
        // If peekPtr is null, it means we need to remove the head
        if(peekPtr == nullptr) {
            return head->next;
        }
        // Move peekPtr 1 step ahead
        // so that when it reaches the end, ptr will be at the node before the one we want to remove
        peekPtr = peekPtr->next;
        // Move both pointers until peekPtr reaches the end
        while(peekPtr != nullptr) {
            peekPtr = peekPtr->next;
            ptr = ptr->next;
        }
        // Now ptr is at the node before the one we want to remove
        // Remove the nth node from the end
        ptr->next = (ptr->next)->next;
        // Return the head of the modified list
        return head;
    }
};