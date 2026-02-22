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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* ans = new ListNode(-1);;
        ListNode* ansTail = ans;

        while(list1 && list2)
        {
            if(list1->val >= list2->val)
                swap(list1, list2);
            ansTail->next = list1;
            list1 = list1->next;
            ansTail = ansTail->next;
        }

        if(list1)
            ansTail->next = list1;
        if(list2)
            ansTail->next = list2;

        ListNode* toDelete = ans;
        ans = ans->next;
        delete toDelete;
        return ans;
    }
};