// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& nums, int index, int diff, vector<unordered_map<int,int>>& dp){
        if(index < 0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];
        }
        int ans = 0;
        for(int j=index-1; j>=0; j--){
            if(nums[index]-nums[j] == diff){
                ans = max(ans, 1 + solve(nums,j,diff,dp));
            }
        }
        return dp[index][diff] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        vector<unordered_map<int,int>> dp(n);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int diff = nums[j] - nums[i];
                ans = max(ans, 2 + solve(nums,i,diff,dp));
            }
        }
        return ans;
    }
};

// TABULATION

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        vector<unordered_map<int,int>> dp(n);
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }

                dp[i][diff] = 1 + cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
