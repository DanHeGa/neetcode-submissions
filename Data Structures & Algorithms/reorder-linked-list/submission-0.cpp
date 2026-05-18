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

class Solution {
public:
    void reorderList(ListNode* head) {
        //go to the middle of the list
        ListNode* slow = head;
        ListNode* fast = slow->next;

        while(fast && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reorder second half of list
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            tmp = tmp->next;
        }
        //at this point, prev is head of the second list reversed
        //and head is for the left first list

        ListNode* first = head;
        ListNode* second = prev;

        while(second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
