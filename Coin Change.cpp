// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int noOfCoins = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins,amount-coins[i],dp);
            if(ans != INT_MAX){
                noOfCoins = min(noOfCoins, 1 + ans);
            }
        }
        return dp[amount] = noOfCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = solve(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};

// TABULATION

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            int noOfCoins = INT_MAX;
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0){
                    int ans = dp[i-coins[j]];
                    if(ans != INT_MAX){
                        noOfCoins = min(noOfCoins,1+ans);
                    }
                }
            }
            dp[i] = noOfCoins;
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
