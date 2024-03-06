class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> subsequence;
        subsequence.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > subsequence.back()){
                subsequence.push_back(nums[i]);
            }
            else{
                int index = lower_bound(subsequence.begin(),subsequence.end(),nums[i]) - subsequence.begin();
                subsequence[index] = nums[i];
            }
        }
        return subsequence.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> nums;
        for(int i=0; i<envelopes.size(); i++){
            nums.push_back(envelopes[i][1]);
        }
        return lengthOfLIS(nums);
    }
};
