/*Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* r=head,*p=head,*q;
        if(!head||!head->next)
            return head;
        else
        {
            q=head->next;
            while(q)
            {
                if(p->val==q->val)
                {
                    r->next=q->next;
                    delete q;
                    q=r->next;
                }
                else
                {
                    p=q;
                    r=p;
                    q=q->next;
                }
            }
            return head;
        }
    }
};
