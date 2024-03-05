// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MIN;
        for(int k=i; k<=j; k++){
            int temp = nums[i-1]*nums[k]*nums[j+1] + solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp);
            ans = max(ans, temp);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,1,n-2,dp);
    }
};

// TABULATION

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-2; i>=1; i--){
            for(int j=1; j<=n-2; j++){
                if(i>j){
                    continue;
                }
                int ans = INT_MIN;
                for(int k=i; k<=j; k++){
                    int temp = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n-2];
    }
};
