// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int transactions, vector<vector<vector<int>>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(transactions >= 2){
            return 0;
        }

        if(dp[index][buy][transactions] != -1){
            return dp[index][buy][transactions];
        }

        int profit = 0;
        if(buy == 0){
            profit = max(solve(prices,index+1,0,transactions,dp), - prices[index] + solve(prices,index+1,1,transactions,dp));
        }
        else{
            profit = max(solve(prices,index+1,1,transactions,dp), prices[index] + solve(prices,index+1,0,transactions+1,dp));
        }
        return dp[index][buy][transactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,0,0,dp);
    }
};

// TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int index = prices.size()-1; index>=0; index--){
            for(int buy = 1; buy>=0; buy--){
                for(int transactions = 1; transactions>=0; transactions--){
                    int profit = 0;
                    if(buy == 0){
                        profit = max(dp[index+1][0][transactions], - prices[index] + dp[index+1][1][transactions]);
                    }
                    else{
                        profit = max(dp[index+1][1][transactions], prices[index] + dp[index+1][0][transactions+1]);
                    }
                    dp[index][buy][transactions] = profit;
                }
            }
        }
        return dp[0][0][0];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));

        for(int index = prices.size()-1; index>=0; index--){
            for(int buy = 1; buy>=0; buy--){
                for(int transactions = 1; transactions>=0; transactions--){
                    int profit = 0;
                    if(buy == 0){
                        profit = max(next[0][transactions], - prices[index] + next[1][transactions]);
                    }
                    else{
                        profit = max(next[1][transactions], prices[index] + next[0][transactions+1]);
                    }
                    curr[buy][transactions] = profit;
                }
            }
            next = curr;
        }
        return next[0][0];
    }
};
