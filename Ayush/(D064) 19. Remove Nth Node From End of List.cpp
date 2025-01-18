// Tortoise and Hair Approach - Optimized
// TC: O(n + (len-n)) = O(len)
// SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // move fast n moves
        for (int i = 0; i < n; i++) fast = fast->next;
        if (fast == NULL) return head->next; // nth is head

        while(fast-> next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // delete the nth node
        ListNode* delnode = slow ->next; 
        slow ->next = slow->next->next;
        delete delnode;
        return head;
    }
};

// Brute Force
// TC: O(len + (len-n)) = O(2len)
// SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        int cnt =0;
        ListNode* temp = head;
        // cnt length of ll
        while(temp!= NULL){
            cnt++;
            temp = temp->next;
        }

        // head to be removed
        if(cnt == n){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        // 
        int res = cnt -n;
        temp = head;
        while(temp!=NULL){
            res--;
            if(res==0) break; // on the node which has been deleted
            temp = temp->next;
        }
        // delete nth from end
        ListNode* delnode =temp->next;
        temp ->next = temp->next->next;
        delete delnode;
        return head;
    }
};