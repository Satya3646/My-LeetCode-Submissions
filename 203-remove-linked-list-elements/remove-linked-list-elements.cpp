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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* it = head;
        ListNode* prev = nullptr;
        while(it)
        {
            if(it->val == val)
            {
                if(it == head)
                    head = head->next;
                else
                    prev->next = it->next;
            }
            else
                prev  = it;
                
            it  = it->next;
        }

        return head;
    }
};