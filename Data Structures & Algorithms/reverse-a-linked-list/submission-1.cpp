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

    ListNode* dfs(ListNode* prev, ListNode* curr) {
        if (!curr) return prev;

        ListNode* snd = curr->next;
        curr->next = prev;

        return dfs(curr, snd);
    }

    ListNode* reverseList(ListNode* head) {
        return dfs(nullptr, head);
    }
};
