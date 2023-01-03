/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* r=nullptr,*head=nullptr,*p=list1,*q=list2;
        if(!p&&!q)
            return head;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(p->val<=q->val)
        {
            r=p;
            head=p;
            p=p->next;
        }
        else
        {
            r=q;
            head=q;
            q=q->next;
        }
        while(p&&q)
        {
            if(p->val<=q->val)
            {
                r->next=p;
                r=p;
                p=p->next;
            }
            else
            {
                r->next=q;
                r=q;
                q=q->next;
            }
        }
        if(p)
            r->next=p;
        if(q)
            r->next=q;
        return head;
    }
};
