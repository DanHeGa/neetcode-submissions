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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* aux = head;
        while(aux) {
            count++;
            aux = aux->next;
        }
        cout << "Count: " << count << endl;

        int objective = count - n;
        if (objective == 0){
            return head->next;
        }

        aux = head;
        for(int i = 0; i < count - 1; i++) {
            if ((i + 1) == objective) {
                aux->next = aux->next->next;
                break;
            }
            aux = aux->next;
        }

        return head;
    }
};
