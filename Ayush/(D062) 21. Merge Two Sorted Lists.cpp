//optimal - change Links
// TC: O(n1+n2)
// SC: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* t1= list1;
        ListNode* t2= list2;
        ListNode* dummy= new ListNode(-1);
        ListNode* temp= dummy;

        while(t1!=NULL && t2!=NULL){
            if(t1->val <t2->val){
                temp->next = t1;
                temp =t1;
                t1 = t1->next;
            }
            else{
                temp ->next = t2;
                temp = t2;
                t2= t2->next;
            }
            // left over part
            if(t1) temp->next = t1;
            else temp->next = t2;

        }   
            return dummy->next;
    }
};

// Brute : copy to arr
// TC : O(n1+n2+nlogn+n)
// SC: O(n)
class Solution {
public:
    ListNode* cvtArrToLL(vector<int>&arr){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        // traverse arr and create node
        for(int i =0; i<arr.size(); i++){
            temp->next = new ListNode(arr[i]);
            temp = temp ->next;
        }
        return dummy->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp1 = list1;
        while(temp1!= NULL){
            arr.push_back(temp1->val);
            temp1 = temp1 ->next;
        }
        ListNode* temp2 = list2;
        while(temp2!= NULL){
            arr.push_back(temp2->val);
            temp2 = temp2 ->next;
        }
        sort(arr.begin(), arr.end());
        // arr to LL
        ListNode* head = cvtArrToLL(arr);
        return head;
    }
};