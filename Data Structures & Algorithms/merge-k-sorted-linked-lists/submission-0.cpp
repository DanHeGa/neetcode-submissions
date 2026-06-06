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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                res->next = l1;
                l1 = l1->next;
            } else {
                res->next = l2;
                l2 = l2->next;
            }

            res = res->next;
        }

        if (l1) {
            res->next = l1;
        } else {
            res->next = l2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();
        for (int i = 0; i < n - 1; i++) {
            lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);
        }

        return lists[n - 1];
    }
};

// 0  1  2  3  4 idx
//[1, 2, 3, 4, 5] values if n = 5, 5-1 = 4, if i<4 :: i max == 3;
