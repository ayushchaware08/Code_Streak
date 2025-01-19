// Optimal one
// TC: O(n) + O(n-(N%k)) == o(n
// SC: O(1))
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        ListNode* temp = head;
        int len = 1;
        // / calc len
        while(temp->next!= NULL){
            ++len;
            temp = temp->next;
        }
        // linking last node to first node
        temp -> next = head;

        k = k%len; // all the multiple of k have same postion as orignal
        int end = len-k; // end of rotated LL 
        while(end--) temp = temp->next;

        // break link to make it last node
        head = temp->next;
        temp->next= NULL;

        return head;
    }
};

// Brutr Force - move last node to first and update head
// TC: O(k*n)
// SC: o(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        // move last ele to first k times
        for(int i =0; i<k; i++){
            ListNode* temp = head;
            // cnt len
            while(temp ->next->next != NULL) temp= temp->next;
            
            ListNode* end = temp->next; // last node
            temp ->next = NULL; // remove link
            end ->next = head; // first position
            head = end;
        }
        return head;
    }
};