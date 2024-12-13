class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0, totalcost =0;
        for(int i =0; i<gas.size();i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalgas<totalcost){
            return -1;
        }
        int currgas =0;
        int start =0;
        for(int i=0;i<gas.size();i++){
            currgas+=gas[i]-cost[i];
            if(currgas<0){ // not able to complete the circuit
                currgas =0;
                start=i+1;
            }
        }
        return start;
    }
};