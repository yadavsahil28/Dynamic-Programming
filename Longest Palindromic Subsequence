class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b = a;
        reverse(b.begin(),b.end());
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
