// Optimal
//  TC: O(n/2)
// SC: O(1) 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
         ListNode* slow = head;
         ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }
};

// Brute Force
// TC: O(n+n/2)
// SC: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp =head;
        int cnt =0;
        // conut total nodes
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        int midnode = (cnt/2)+1;
        temp = head;
        // posn of middle node
        while(temp != NULL){
            midnode--;
            if(midnode==0) break;
            temp=temp->next;
        }
        return temp;
    } 
};