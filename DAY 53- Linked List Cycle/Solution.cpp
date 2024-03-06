class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(0);
        if(!head)return false;
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL)fast=fast->next;
            slow=slow->next;
            if(fast==slow && fast!=NULL)return true;
        }
        return false;
    }
};
