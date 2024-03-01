// MEMOIZATION

int solve(int capacity, int wt[], int val[], int n, int index, vector<vector<int> >& dp){
    if(index == n || capacity == 0)
        return 0;
        
    if(dp[index][capacity] != -1)
        return dp[index][capacity];
    
    int include = 0;
    if(capacity >= wt[index]){
        include = val[index] + solve(capacity-wt[index], wt,val, n, index+1,dp);
    }
    int exclude = solve(capacity,wt,val,n,index+1,dp);
    return dp[index][capacity] = max(include,exclude);
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int> > dp(n+1, vector<int>(W+1, -1));
   return solve(W,wt,val,n, 0,dp);
}


// TABULATION

int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int> > dp(n+1, vector<int>(W+1, 0));
    
    for(int index = n-1; index>=0; index--){
        for(int capacity = 0; capacity<=W; capacity++){
            int include = 0;
            if(capacity >= wt[index]){
                include = val[index] + dp[index+1][capacity-wt[index]];
            }
            int exclude = dp[index+1][capacity];
            dp[index][capacity] = max(include,exclude);
        }
    }
    return dp[0][W];
}
