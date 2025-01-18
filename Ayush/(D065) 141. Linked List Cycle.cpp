// Optimal one
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast== slow) return true;
        }
        return false;
    }
};

// Brute force
// TC: O(n * 2 * logn)
// SC: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp!=NULL){
            if(mpp.find(temp)!= mpp.end()) return true;
            mpp[temp] =1;
            temp = temp->next;
        }
        return false;
    }
};