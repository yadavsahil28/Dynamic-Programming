// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(nums,curr+1,curr,dp);
        }

        int notTake = solve(nums,curr+1,prev,dp);
        return dp[curr][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};

// TABULATION

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int curr = n-1; curr>=0; curr--){
            for(int prev = n-1 ; prev>=-1; prev--){
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    take = 1 + dp[curr+1][curr+1];
                }

                int notTake = dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};

// SPACE OPTIMIZED

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = n-1 ; prev>=-1; prev--){
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    take = 1 + nextRow[curr+1];
                }

                int notTake = nextRow[prev+1];
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};

// MOST OPTIMAL

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> subsequence;
        subsequence.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > subsequence.back()){
                subsequence.push_back(nums[i]);
            }
            else{
                int index = lower_bound(subsequence.begin(),subsequence.end(),nums[i]) - subsequence.begin();
                subsequence[index] = nums[i];
            }
        }
        return subsequence.size();
    }
};
