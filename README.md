# Gas Station (LeetCode 134)
In this DSA problem we will be given with the two arrays one is Gas array that is available to us for moving from that station to other and the other is cost array which gives the required amount of gas to move to next station . In this, we have to return the index from which in Gas array we should start so that we can complete our circular track

## Problem Link 
 https://leetcode.com/problems/gas-station/
## Approach
- Calculate total gas and total cost.
- If total gas < total cost, return `-1`.
- Traverse the stations while maintaining the current tank.
- Whenever the tank becomes negative, reset the starting station to the next index.
## Complexity Analysis

Time Complexity : O(n)
Space Complexity : O(1)

## Solution

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

