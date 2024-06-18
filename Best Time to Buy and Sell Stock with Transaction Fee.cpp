// MEMOIZATION

class Solution {
public:
    int stock(vector<int>& prices, bool bought, int index, int fee, int n, vector<vector<int>>& dp){
        if(index == n){
            return 0;
        }

        if(dp[index][bought] != -1)
            return dp[index][bought];

        int profit;
        if(!bought){
            int not_buy = stock(prices, false, index+1, fee, n, dp);
            int buy = -prices[index] + stock(prices, true, index+1, fee, n, dp);
            profit = max(buy,not_buy);
        }
        else{
            int not_sell =  stock(prices, true, index+1, fee, n, dp);
            int sell = prices[index] - fee + stock(prices, false, index+1, fee, n, dp);
            profit = max(sell, not_sell);
        }
        return dp[index][bought] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int n = prices.size();
        return stock(prices,false,0,fee,n,dp);
    }
};

// TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        int n = prices.size();
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                int profit;
                if(buy){
                    int not_buy = dp[index+1][1];
                    int buy = -prices[index] + dp[index+1][0];
                    profit = max(buy,not_buy);
                }
                else{
                    int not_sell =  dp[index+1][0];
                    int sell = prices[index] - fee + dp[index+1][1];
                    profit = max(sell, not_sell);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(next[1], -prices[index] + next[0]);
                }
                else{
                    profit = max(next[0],prices[index] - fee + next[1]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};
