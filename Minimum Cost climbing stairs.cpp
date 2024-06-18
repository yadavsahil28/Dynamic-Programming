// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& cost, int i, vector<int>& dp){
        if(i == 0 || i == 1){
            return cost[i];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = cost[i] + min(solve(cost,i-2,dp), solve(cost,i-1,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        
        return min(solve(cost,n-2,dp),solve(cost,n-1,dp));
    }
};

// TABULATION

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++){
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];

        for(int i=2; i<n; i++){
            int curr = min(first,second) + cost[i];
            first = second;
            second = curr;
        }
        return min(first,second);
    }
};
