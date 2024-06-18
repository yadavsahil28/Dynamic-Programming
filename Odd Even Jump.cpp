class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        // Set goodIndices to 1 since we can always reach the end
        // by starting at the rightmost position of the array.
        int n = arr.size();
        int goodIndices = 1;

        vector<vector<bool>> dp(n,vector<bool>(2,0));

        // ordered map to efficiently get next greater and
        // next smaller element to right
        map<int,int> coveredNums;

        // if we start at the last array position,
        // we have already reached the end of the array
        // so both odd or even jumps will work 
        dp[n-1][0] = 1;
        dp[n-1][1] = 1;

        // insert the last number in the array into the ordered map
        // coveredNums[number] = index of number
        coveredNums[arr[n-1]] = n-1;

        // iterate from right to left over array
        for(int i=n-2; i>=0; i--){
            // get the smallest number that is greater than
            // or equal to arr[i] that is to the right of arr[i]
            auto it = coveredNums.lower_bound(arr[i]);

            // need to handle the special case of 
            // there being another element equal to arr[i]
            // to the right. In this case, both odd and even jumps
            // will end up at the same spot, the position of
            // the leftmost element to the right which equals arr[i].
            if(it->first == arr[i]){
                dp[i][0] = dp[it->second][1];
                dp[i][1] = dp[it->second][0];
                // regular case where there are no elements
                // to the right of arr[i] which equal arr[i]
            }
            else{
                // If arr[i] is bigger than all elements 
                // to the right, an odd jump is not possible.
                // But an even jump to the largest element 
                // in the ordered map is possible.
                if(it == coveredNums.end()){
                    dp[i][0] = dp[prev(it)->second][1];
                    dp[i][1] = 0;
                    // If arr[i] is smaller than all elements 
                    // to the right, an even jump is not possible.
                    // But an odd jump to the smallest element 
                    // in the ordered map is possible.
                }
                else if(it == coveredNums.begin()){
                    dp[i][0] = 0;
                    dp[i][1] = dp[it->second][0];
                    // if the lower bound of arr[i] is
                    // nither the smallest or the largest element 
                    // to the right of arr[i], then both odd and 
                    // even jumps are possible.
                }
                else{
                    dp[i][0] = dp[prev(it)->second][1];
                    dp[i][1] = dp[it->second][0];
                }
            }
            // add arr[i] to the ordered map
            coveredNums[arr[i]] = i;

            // increment goodIndices if we can reach the end by
            // doing an odd jump from position i.
            goodIndices += dp[i][1];
        }
        return goodIndices;
    }
};
