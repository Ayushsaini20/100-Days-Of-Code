class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> prefixSumToNode;
        int prefixSum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            prefixSum += current->val;
            if (prefixSumToNode.count(prefixSum)) {
                ListNode* prev = prefixSumToNode[prefixSum];
                ListNode* toRemove = prev->next;
                int p = prefixSum + (toRemove ? toRemove->val : 0);
                while (p != prefixSum) {
                    prefixSumToNode.erase(p);
                    toRemove = toRemove->next;
                    p += (toRemove ? toRemove->val : 0);
                }
                prev->next = current->next;
            } else {
                prefixSumToNode[prefixSum] = current;
            }
        }
        return dummy->next;
    }
};
