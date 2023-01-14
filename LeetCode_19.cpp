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
        int len = 0;
        ListNode* cur = head;
        ListNode* skip;
        while(cur) {
            cur = cur->next;
            len++;
        }
        
        if(n == len) {
            return head->next;
        }

        cur = head;
        for(int i = 0; i < len-n-1; i++) {
            cur = cur->next;
        }
        if(cur->next) {
            skip = cur->next;
        }
        if(skip) {
            cur->next = skip->next;
        }
        delete skip;

        return head;
    }
};