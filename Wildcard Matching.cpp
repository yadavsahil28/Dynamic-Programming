// MEMOIZATION

class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(i == s.size() && j == p.size()){
            return true;
        }

        if(i == s.size()){
            for(int index=j; index<p.size(); index++){
                if(p[index] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(j == p.size()){
            return false;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool ans = false;
        if(s[i] == p[j] || p[j] == '?'){
            ans = solve(s,p,i+1,j+1,dp);
        }
        else if(p[j] == '*'){
            ans = (solve(s,p,i+1,j,dp) || solve(s,p,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,0,0,dp);
    }
};

// TABULATION

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
        dp[s.size()][p.size()] = 1;
        for(int j=0; j<p.size(); j++){
            bool flag = true;
            for(int index=j; index<p.size(); index++){
                if(p[index] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[s.size()][j] = flag;
        }
        for(int i=s.size()-1; i>=0; i--){
            for(int j=p.size()-1; j>=0; j--){
                bool ans = false;
                if(s[i] == p[j] || p[j] == '?'){
                    ans = dp[i+1][j+1];
                }
                else if(p[j] == '*'){
                    ans = (dp[i+1][j] || dp[i][j+1]);
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
    bool isMatch(string s, string p) {
        vector<int> curr(p.size()+1,0);
        vector<int> next(p.size()+1,0);
        next[p.size()] = 1;
        for(int j=0; j<p.size(); j++){
            bool flag = true;
            for(int index=j; index<p.size(); index++){
                if(p[index] != '*'){
                    flag = false;
                    break;
                }
            }
            next[j] = flag;
        }
        for(int i=s.size()-1; i>=0; i--){
            for(int j=p.size()-1; j>=0; j--){
                bool ans = false;
                if(s[i] == p[j] || p[j] == '?'){
                    ans = next[j+1];
                }
                else if(p[j] == '*'){
                    ans = (next[j] || curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};
