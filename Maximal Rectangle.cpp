class Solution {
public:
    vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for(int i=0; i<n; i++){
            int item = heights[i];

            while(s.top() != -1 && heights[s.top()] >= item){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for(int i=n-1; i>=0; i--){
            int item = heights[i];

            while(s.top() != -1 && heights[s.top()] >= item){
                s.pop();
            }

            if(s.top() == -1){
                ans[i] = n;
            }
            else{
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int ans = INT_MIN;

        for(int i=0; i<heights.size(); i++){
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            ans = max(ans, l*b);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = INT_MIN;
        vector<int> heights(matrix[0].size(),0);

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<heights.size(); j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }
};
