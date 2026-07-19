
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
     
        int maxTwinSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        
        while (secondHalf != nullptr) {
            int currentSum = firstHalf->val + secondHalf->val;
            maxTwinSum = std::max(maxTwinSum, currentSum);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxTwinSum;
    }
};