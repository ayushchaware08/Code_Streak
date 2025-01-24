// Optimal One
// TC o(3n)
// SC o(n)

class Solution {
public:

    void insertCopy(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nextEle = temp ->next;
            Node* copy = new Node(temp->val); // copy node
            // inset copy node in between org LL
            copy ->next = nextEle;
            temp -> next = copy;

            temp = nextEle;
        }
    }

    void connectRandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copy = temp ->next; // access the copied node
            if(temp -> random){
                // connect random ptr of copied node to copied random done
                copy ->random = temp -> random ->next;
            }
            else{ // point it to null
                copy ->random = NULL;
            }
            temp = temp->next->next; // point to org ll node
        }
    }

    Node* getDeepCopy(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* result = dummy; // result ptr

        while(temp!=NULL){
            // seperate the copird nodes
            result -> next = temp->next;
            result = result ->next;

            // to reverse all the changes made to org LL
            // copied LL and Orignal LL seperated (maintained the structure of org LL)
            temp ->next = temp->next->next;
            temp = temp ->next;
        }
        return dummy ->next;
    }
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }

        // steps to do so
        insertCopy(head);
        connectRandom(head);
        return getDeepCopy(head);

    }
};

// brute Force
// TC O(2n)
// SC o(2n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mpp;
        // traverse and store LL
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode;
            temp = temp ->next;
        }
        temp = head;
        // connect links
        while(temp!=NULL){
            Node* copyNode = mpp[temp];
            copyNode -> next = mpp[temp->next];
            copyNode -> random = mpp[temp->random];
            temp = temp ->next;
        }
        return mpp[head];
    }
};