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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* it = head;
        while(it)
        {
            // Store the current node.
            ListNode* curr = it;
            it = it->next; // move to next node.
            // if next nodes have same value as current keep on deleting.
            while(it && it->val == curr->val)
            {
                // ListNode* toDelete = it; // store to later erase the node.
                curr->next = it->next; // disconnect the duplicate node.
                it = it->next;
                // delete toDelete;
            }
        }
        return head;
    }
};