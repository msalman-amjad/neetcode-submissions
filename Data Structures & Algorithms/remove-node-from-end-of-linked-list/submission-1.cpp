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
        //Step 1
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 2: Move fast pointer n + 1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Step 3: Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 4: Bypass the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        
        // Step 5: Free memory of the removed node
        delete toDelete; 

        // Step 6: Clean up dummy node and return the updated list
        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
        
    }
};
