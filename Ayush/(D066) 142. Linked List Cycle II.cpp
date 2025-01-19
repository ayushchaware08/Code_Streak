// Optimal Solution
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==nullptr) return NULL;//-//
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){ // loop found
                slow=head;
                // find the first node of loop
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                    // the place where slow fast meet again is the first node
                }
                return slow;
            }
        }
        return NULL;
    }
};

// Brute
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;
        // traverse ll and mark visite
        while(temp!=NULL){
            if(mpp.count(temp)!=0){// loop detected
                return temp; // return loop starting point
            }
            mpp[temp] = 1;
            temp= temp->next;
        }
        return nullptr;
    }
};