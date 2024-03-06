class Solution {
public:
    int solve(vector<int>& rods, int i, int sum, vector<unordered_map<int,int>>& dp){
        if(i >= rods.size()){
            if(sum){
                return INT_MIN;
            }
            return 0;
        }

        if(dp[i].count(sum)){
            return dp[i][sum];
        }

        int op1 = rods[i] + solve(rods,i+1,sum + rods[i],dp);
        int op2 = solve(rods,i+1,sum-rods[i],dp);
        int op3 = solve(rods,i+1,sum,dp);
        return dp[i][sum] = max(op1,max(op2,op3));
    }
    int tallestBillboard(vector<int>& rods) {
        vector<unordered_map<int,int>> dp(rods.size());
        return solve(rods,0,0,dp);
    }
};
