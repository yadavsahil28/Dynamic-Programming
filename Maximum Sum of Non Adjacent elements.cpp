// MEMOIZATION

#include <bits/stdc++.h> 
int solve(vector<int>& nums, int i, vector<int>& dp){
    if(i<0){
        return 0;
    }

    if(i==0){
        return nums[0];
    }

    if(dp[i] != -1){
        return dp[i];
    }
    int exclude = solve(nums,i-1,dp);
    int include = nums[i] + solve(nums,i-2,dp);
    return dp[i] = max(exclude,include);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(nums,n-1,dp);
}

// TABULATION

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i=1; i<n; i++){
        int exclude = dp[i-1];
        int include = dp[i-2] + nums[i];
        dp[i] = max(exclude,include);
    }
    return dp[n-1];
}

// SPACE OPTIMIZATION

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int exclude = prev1;
        int include = prev2 + nums[i];
        int ans = max(exclude,include);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
