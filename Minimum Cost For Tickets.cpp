// MEMOIZATTION

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,vector<int>& dp, int index){
        if(index >= days.size()){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }

        int oneDay = costs[0] + solve(days,costs,dp,index+1);

        int i;
        for(i=index; i<days.size() && days[i] < days[index] + 7; i++);
        int sevenDay = costs[1] + solve(days,costs,dp,i);
        
        for(i=index; i<days.size() && days[i] < days[index] + 30; i++);
        int thirtyDay = costs[2] + solve(days,costs,dp,i);

        return dp[index] = min(oneDay,min(sevenDay,thirtyDay));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(days,costs,dp,0);
    }
};

// TABULATION

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;

        for(int k=n-1; k>=0; k--){
            int oneDay = costs[0] + dp[k+1];

            int i;
            for(i=k; i<days.size() && days[i] < days[k] + 7; i++);
            int sevenDay = costs[1] + dp[i];
            
            for(i=k; i<days.size() && days[i] < days[k] + 30; i++);
            int thirtyDay = costs[2] + dp[i];

            dp[k] = min(oneDay,min(sevenDay,thirtyDay));
        }
        return dp[0];
    }
};
