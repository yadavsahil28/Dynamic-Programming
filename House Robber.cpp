// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1)
            return dp[i];

        int include = nums[i] + solve(nums, i+2, dp);
        int exclude = solve(nums, i+1, dp);

        return dp[i] = max(include,exclude);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0,dp);   
    }
};

// TABULATION

class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, 0);

        for(int i=n-1; i>=0; i--){
            int include = nums[i] + dp[i+2];
            int exclude = dp[i+1];

            dp[i] = max(include,exclude);
        }  
        return dp[0];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        int next1 = 0;
        int next2  = 0;
        int curr;

        for(int i=n-1; i>=0; i--){
            int include = nums[i] + next2;
            int exclude = next1;

            curr = max(include,exclude);
            next2 = next1;
            next1 = curr;
        }  
        return curr;
    }
};
