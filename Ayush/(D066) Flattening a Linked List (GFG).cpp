// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Optimal Approach
// TC: o(n*2m)
// SC: o(1)
class Solution {
  public:
  // Merger
  Node* merge(Node* list1, Node* list2){
      Node* dummy = new Node(-1);
      Node* ans = dummy;
    //   .. merger
    while(list1!=NULL && list2!=NULL){
        if(list1->data <list2->data){
            ans->bottom = list1;
            ans = list1;
            list1 = list1->bottom;
        }
        else{
            ans ->bottom = list2;
            ans = list2;
            list2 = list2->bottom;
        }
        ans->next = NULL;
        }
        // remaining items
        if(list1) ans->bottom = list1;
        else ans->bottom = list2;
        
        // to prevent cycle break last node link
        if(dummy->bottom){
            dummy->bottom->next = NULL;
        }
        return dummy -> bottom;
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root == NULL || root->next==NULL){
            return root;
        }
        
        // recursive flattern
        Node* mergedHead = flatten(root->next);
        root = merge(root, mergedHead);
        return root;
        // Your code here
    }
};

// Brute Force
//TC: o(n*m + n*mlog(n*m) + n*m)
// SC: o(n*m) sorting + O(n*m) ----------------
class Solution {
  public:
    Node* arrToLL(vector<int>& ans){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        for(int i =0; i<ans.size(); i++){
            temp->bottom = new Node(ans[i]);
            temp = temp->bottom;
        }
        return dummy->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        vector<int> ans;
        // traverse through next LL 
        while(root!=nullptr){
            Node* temp = root;
            // traverse thorugh bottom(child)
            while(temp!=nullptr){
                ans.push_back(temp->data);
                temp = temp->bottom;
            }
            root = root->next;
        }
        sort(ans.begin(), ans.end());
        return arrToLL(ans);
    }
};