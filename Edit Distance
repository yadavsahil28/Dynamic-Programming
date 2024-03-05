// MEMOIZATION

class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans = solve(a,b,i+1,j+1,dp);
        }
        else{
            int insertAns = solve(a,b,i,j+1,dp);
            int deleteAns = solve(a,b,i+1,j,dp);
            int replaceAns = solve(a,b,i+1,j+1,dp);

            ans = 1 + min({insertAns,deleteAns,replaceAns});
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1,word2,0,0,dp);
    }
};

// TABULATION

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        
        for(int j=0; j<word2.size(); j++){
            dp[word1.size()][j] = word2.size() - j;
        }
        for(int i=0; i<word1.size(); i++){
            dp[i][word2.size()] = word1.size() - i;
        }

        for(int i=word1.size()-1; i>=0; i--){
            for(int j=word2.size()-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insertAns = dp[i][j+1];
                    int deleteAns = dp[i+1][j];
                    int replaceAns = dp[i+1][j+1];

                    ans = 1 + min(insertAns,min(deleteAns,replaceAns));
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
    int minDistance(string word1, string word2) {
        vector<int> curr(word2.size()+1,0);
        vector<int> next(word2.size()+1,0);

        for(int j=0; j<word2.size(); j++){
            next[j] = word2.size() - j;
        }
        
        for(int i=word1.size()-1; i>=0; i--){
            curr[word2.size()] = word1.size() - i;
            for(int j=word2.size()-1; j>=0; j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = next[j+1];
                }
                else{
                    int insertAns = curr[j+1];
                    int deleteAns = next[j];
                    int replaceAns = next[j+1];

                    ans = 1 + min(insertAns,min(deleteAns,replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};
