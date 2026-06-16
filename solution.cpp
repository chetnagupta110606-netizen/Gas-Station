class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0;
        int currGas=0;
        int sumGas=0,sumCost=0;
      
        if(sumGas<sumCost){
            return -1;
        }
        for(int i=0;i<gas.size();i++){
            sumCost+=cost[i];
            sumGas+=gas[i];
            currGas +=gas[i]-cost[i];
            if(currGas<0){
                st=i+1;
                currGas=0;
            }
        }
        return sumCost>sumGas?-1:st;
    }
};
