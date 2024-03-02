// MEMOIZATION

class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j,vector<vector<int>>& dp, int& maxi){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int bottom = solve(matrix,i+1,j,dp,maxi);
        int diagonal = solve(matrix,i+1,j+1,dp,maxi);
        int right = solve(matrix,i,j+1,dp,maxi);

        if(matrix[i][j] == '1'){
            int ans = 1 + min(bottom,min(diagonal,right));
            maxi = max(maxi,ans);
            dp[i][j] = ans;
        }
        else{
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi = 0;
        solve(matrix,0,0,dp,maxi);
        int area = maxi*maxi;
        return area;
    }
};

// TABULATION

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int bottom = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                int right = dp[i][j+1];
                if(matrix[i][j] == '1'){
                    int ans = 1 + min(bottom,min(diagonal,right));
                    maxi = max(maxi,ans);
                    dp[i][j] = ans;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int area = maxi*maxi;
        return area;
    }
};

// SPACE OPTIMIZATION

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        int maxi = 0;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int bottom = next[j];
                int diagonal = next[j+1];
                int right = curr[j+1];
                if(matrix[i][j] == '1'){
                    int ans = 1 + min(bottom,min(diagonal,right));
                    maxi = max(maxi,ans);
                    curr[j] = ans;
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        int area = maxi*maxi;
        return area;
    }
};
