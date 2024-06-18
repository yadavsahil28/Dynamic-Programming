// MEMOIZATION

class Solution {
public:
    int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.size() || j == text2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solve(text1,text2,i+1,j+1,dp);
        }
        else{
            ans = max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,dp);
    }
};

// TABULATION

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i=text1.size()-1; i>=0; i--){
            for(int j=text2.size()-1; j>=0; j--){
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<int> curr(b.length()+1,0);
        vector<int> next(b.length()+1,0);

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--) {
                int ans = 0;
                //match
                if(a[i] == b[j]) {
                    ans = 1 + next[j+1];
                }     
                else {
                    int op1 = next[j];
                    int op2 = curr[j+1];
                    ans = max(op1, op2);
                }
                curr[j] = ans; 
            }
            next = curr;
        }
        return curr[0];
    }
};
