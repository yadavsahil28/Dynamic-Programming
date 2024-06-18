// MEMOIZATION

class Solution {
public:
    int solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp){
        if(currpos == obstacles.size()-1){
            return 0;
        }

        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }

        int finalAns = 0;
        if(currlane != obstacles[currpos + 1]){
            finalAns = solve(obstacles,currlane,currpos + 1,dp);
        }
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(i != currlane && i != obstacles[currpos]){
                    ans = min(ans, 1 + solve(obstacles,i,currpos+1,dp));
                }
            }
            finalAns = ans;
        }
        return dp[currlane][currpos] = finalAns;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solve(obstacles,2,0,dp);
    }
};

// TABULATION

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size()-1;
        vector<vector<int> > dp(4,vector<int>(obstacles.size(),0));
        
        // actuall ye n-2 h kkyuki n - 1 upr bhi h n calculate krne me
        for(int currpos = n-1; currpos>=0; currpos--){
            for(int currlane = 1; currlane<=3; currlane++){
                if(currlane != obstacles[currpos + 1]){
                    dp[currlane][currpos] = dp[currlane][currpos + 1];
                }
                else{
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(i != currlane && i != obstacles[currpos]){
                            ans = min(ans, 1 + dp[i][currpos+1]);
                        }
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    }
};
