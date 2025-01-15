// Optimal - Using Recurssion
// TC: O(n)
// SC: O(n) - recursive stack space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case
        if(head==NULL || head->next == nullptr){
            return head;
        }
        // function
        ListNode* newhead = reverseList(head->next); // head of reversed LL
        ListNode* front = head->next;
        front ->next = head;
        head->next = nullptr;
        return newhead;
    }
};

// Better way - reverse links
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        // return curr head i.e prev;
        return prev;
    }
};

// Brute Force - Stack DS
// TC: O(2N)
// sc: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        // push to stack
        while(temp!=nullptr){
            st.push(temp->val);
            temp = temp->next;
        } 
        temp = head;
        // add top ele to temp and pop
        while(temp!=nullptr){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};