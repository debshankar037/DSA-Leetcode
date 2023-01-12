class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *slow,*fast,*temp,*l1,*l2;
        slow=fast=head;
        while(fast&&fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=nullptr;
        l1=sortList(head);
        l2=sortList(slow);
        return mergelist(l1,l2);
}
    ListNode* mergelist(ListNode* l1,ListNode* l2)
    {
        ListNode* ptr=new ListNode(0);
        ListNode* curr=ptr;
        while(l1&&l2)
        {
            if(l2->val<=l1->val)
            {
                curr->next=l2;
                l2=l2->next;
            }
            else
            {
                curr->next=l1;
                l1=l1->next;
            }
            curr=curr->next;
        }
        if(l1)
            curr->next=l1;
        if(l2)
            curr->next=l2;
        return ptr->next;
    }
};
