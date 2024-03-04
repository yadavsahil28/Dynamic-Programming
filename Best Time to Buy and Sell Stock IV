// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int transactions, int k, vector<vector<vector<int>>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(transactions >= 2*k){
            return 0;
        }

        if(dp[index][buy][transactions] != -1){
            return dp[index][buy][transactions];
        }

        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solve(prices, index+1, 0, transactions+1, k, dp);
            int skipKaro = solve(prices, index+1, 1, transactions, k, dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solve(prices, index+1, 1, transactions+1, k, dp);
            int skipKaro = solve(prices, index+1, 0, transactions, k, dp);
            profit = max(sellKaro, skipKaro);
        }
        return dp[index][buy][transactions] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp (prices.size(), vector<vector<int>>(2, vector<int>(2*k+1,-1)));
        return solve(prices, 0, 1, 0, k, dp);
    }
};

// TABULATION

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp (n+1, vector<int>(2*k+1,0));

        for(int index=n-1; index>=0; index--){
            for(int transactions=0; transactions<2*k; transactions++){
                int profit = 0;
                if(!(transactions&1)){
                    int buyKaro = -prices[index] + dp[index+1][transactions+1];
                    int skipKaro = dp[index+1][transactions];
                    profit = max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro = prices[index] + dp[index+1][transactions+1];
                    int skipKaro = dp[index+1][transactions];
                    profit = max(sellKaro, skipKaro);
                }
                dp[index][transactions] = profit;
            }
        }
        return dp[0][0];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<int>curr (2*k+1,0);
        vector<int>next (2*k+1,0);
        for(int index=n-1; index>=0; index--){
            for(int transactions=0; transactions<2*k; transactions++){
                int profit = 0;
                if(!(transactions&1)){
                    int buyKaro = -prices[index] + next[transactions+1];
                    int skipKaro = next[transactions];
                    profit = max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro = prices[index] + next[transactions+1];
                    int skipKaro = next[transactions];
                    profit = max(sellKaro, skipKaro);
                }
                curr[transactions] = profit;
            }
            next = curr;
        }
        return curr[0];
    }
};
