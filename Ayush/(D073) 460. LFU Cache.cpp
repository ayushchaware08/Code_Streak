// DLL
struct Node{

    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int key_, int value_){
        key = key_;
        value = value_;
        cnt = 1; // frequency
    }
};
// can use stl of list but as per interview
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head -> next = tail;
        tail -> prev = head;
        size =0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delNode){
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev ->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
    map<int , Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache,minFreq, currSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq =0;
        currSize =0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size ==0){
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        // next curr freq
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList  = freqListMap[node->cnt +1];
        }
        node->cnt +=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!= keyNode.end()){ // present 
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(maxSizeCache ==0){
            return ;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{ // not exist
            if(currSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq =1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
}; 

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */