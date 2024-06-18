// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        if(buy == 0){
            profit = max(solve(prices,index+1,0,dp), - prices[index] + solve(prices,index+1,1,dp));
        }
        else{
            profit = max(solve(prices,index+1,1,dp), prices[index] + solve(prices,index+1,0,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};

// TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        for(int index=prices.size()-1; index>=0; index--){
            for(int buy=1; buy>=0; buy--){
                int profit = 0;
                if(buy == 0){
                    profit = max(dp[index+1][0], - prices[index] + dp[index+1][1]);
                }
                else{
                    profit = max(dp[index+1][1], prices[index] + dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][0];
    }
};

// SPACE OPTIMIZED

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> curr(2,0);
        vector<int> next(2,0);
        for(int index=prices.size()-1; index>=0; index--){
            for(int buy=1; buy>=0; buy--){
                int profit = 0;
                if(buy == 0){
                    profit = max(next[0], - prices[index] + next[1]);
                }
                else{
                    profit = max(next[1], prices[index] + next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[0];
    }
};
