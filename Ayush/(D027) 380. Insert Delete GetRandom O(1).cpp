// use vector for more optimization
// TC: O(1) SC:O(n)

#include <bits/stdc++.h>
class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // if present in map: false
        if(s.find(val)!=s.end()) return 0;
        // else absent: true
        else{
            s.insert(val);
            // m[val]=v.size()-1; // m[key]=value
            return 1;
        }
    }
    
    bool remove(int val) {
        //else: absent false;
        if(s.find(val)==s.end()) return 0;
        // if present: true
        else{
            s.erase(val); 
            return 1;
        }
    }
    
    int getRandom() {
        // random value from 0->n-1
        // next(iterator, n) -> STL
        // * -> derefrencer for extraction exact value
        return *next(s.begin(),rand()%s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */