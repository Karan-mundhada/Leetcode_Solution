class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        dp[0] = triangle[0];
        for(int i=1; i<n; i++)
        {
            vector<int> temp(i+1, 10001);
            for(int j=0; j<i+1; j++)
            {
                if(j == 0)
                {
                    temp[j] = triangle[i][j] + dp[i-1][0];
                }
                else if(j == i)
                {
                    temp[j] = triangle[i][j] + dp[i-1][j-1];
                }
                else
                {
                    temp[j] = min(temp[j], triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
            dp[i] = temp;
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};