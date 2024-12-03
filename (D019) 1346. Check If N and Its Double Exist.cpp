// can also use sorting -> binary search with TC: O(nlogn) SC: O(logn) for cpp

// Set
// TC: O(n)
// SC: o(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> visited;
        for (int num : arr) {
            if (visited.count(2 * num) || (num % 2 == 0 && visited.count(num / 2))) return true;
          visited.insert(num);
        }
        return false;
    }
};

// Brute force -- Optimized
// TC: O(n^2)
// SC: o(1)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i<arr.size(); i++){
            for(int j = 0; j<arr.size(); j++){
                if(i!=j && arr[i] == arr[j]*2) return true;
            }
        }
        return false;
    }
};
