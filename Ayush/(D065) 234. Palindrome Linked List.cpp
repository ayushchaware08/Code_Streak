// Optimal Approach
// TC: O(2n)
// SC: O(1)
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next ==NULL) return head;

        ListNode* newhead= reverseLL(head->next);
        ListNode* front = head ->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head ==NULL || head->next ==NULL) return true;
        ListNode* slow =head;
        ListNode* fast = head;
        // find mid (Tortoise and hair approach)
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the half part
        ListNode* newhead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newhead;

        // compare ele head with new head (reversed one)
        while(second != NULL){
            if(first->val != second ->val){
                reverseLL(newhead);
                return false;
            }
            first= first->next;
            second = second->next;
        }

        reverseLL(newhead);
        return true;
    }
};

// Brute Forece
// TC: O(n + n)
// SC: O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       stack<int> st;
       ListNode* temp =head;
       // push data in to stack
       while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
       } 
    //    compare top() with each node from head;
       temp = head;
       while(temp!=NULL){
            if(st.top()!=temp->val) return false;
            temp=temp->next;
            st.pop();
       }
       return true;

    }
};