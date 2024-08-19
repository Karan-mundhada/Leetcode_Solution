class Solution {
public:
    // int jump2(vector<int> nums, vector<int>& dp, int n, int ind)
    // {
    //     if(ind >= n-1) return 0;
    //     if(dp[ind] != 100000) return dp[ind];

    //     for(int j=1; j<=nums[ind]; j++)
    //         dp[ind] = min(dp[ind], 1 + jump2(nums, dp, n, ind + j));
        
    //     return dp[ind];
    // }
    // int jump(vector<int>& nums) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     int n = nums.size();
    //     vector<int> dp(n, 100000);
    //     return jump2(nums, dp, n, 0);
    // }
    int jump(vector<int>& nums) {
	int n = size(nums);
	vector<int> dp(n, 10001);
	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
	// same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
	for(int i = n - 2; i >= 0; i--) 
		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
			dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
	return dp[0];
}
};