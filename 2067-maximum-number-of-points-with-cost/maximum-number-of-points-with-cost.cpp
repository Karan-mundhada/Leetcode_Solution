class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        // Initialize the dp array with the first row of points
        vector<long long> dp(points[0].begin(), points[0].end());
        
        // Temporary vector to store new dp values
        vector<long long> new_dp(m);
        
        for (int i = 1; i < n; i++) {
            // Left to right pass to calculate maximum possible values
            vector<long long> left(m);
            left[0] = dp[0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, dp[j]);
            }
            
            // Right to left pass to calculate maximum possible values
            vector<long long> right(m);
            right[m - 1] = dp[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, dp[j]);
            }
            
            // Compute new dp values for this row
            for (int j = 0; j < m; j++) {
                new_dp[j] = points[i][j] + max(left[j], right[j]);
            }
            
            // Update dp array for the next row
            dp = new_dp;
        }
        
        // The maximum value in the last dp array is the answer
        return *max_element(dp.begin(), dp.end());
    }
};
