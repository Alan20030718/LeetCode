class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 2){
            if(n == 2){
                return min(cost[0],cost[1]);
            }
            return cost[0];
        }
        vector<int> dp(n+1,0);
        for(int i = 2; i<= n; i++){
            dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};