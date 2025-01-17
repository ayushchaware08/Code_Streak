// Dummy node - optimized and clean
// TC: o(2m)
// SC: o(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;

        while(d1!=d2){
            d1 = d1 == NULL ? headB: d1->next;
            d2 = d2 == NULL ? headA: d2->next;
        }
        return d1;
    }
};

// Brute Force
// TC: O(2m)
// SC: o(1)
class Solution {
public:
    int getdiff(ListNode* headA, ListNode *headB){
        int len1=0, len2=0;
        while(headA!=NULL || headB!=NULL){
            if(headA!=NULL){
                ++len1;
                headA=headA->next;
            }
            if(headB!=NULL){
                ++len2;
                headB=headB->next;
            }
        }
        return len1-len2; //-//
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getdiff(headA, headB);
        // check lenght and iterate head of largest one
        if(diff<0){ // headB is greater
            while(diff++ !=0) headB = headB->next;
        }
        else while(diff--!=0) headA = headA->next;

        // condition (both head are at same dist from intersection)
        while(headA!=NULL){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};