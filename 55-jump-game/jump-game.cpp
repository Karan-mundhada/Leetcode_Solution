// class Solution {
// public:
//     bool jump(vector<int> nums, vector<int> dp, int n, int ind)
//     {
//         if(ind == n-1)
//             return true;
//         if(nums[ind] == 0)
//             return false;

//         if(dp[ind] != -1)
//             return dp[ind];        

//         for(int j=1; j<=nums[ind]; j++)
//         {
//             if(j < n && jump(nums, dp, n, ind+j))
//                 return dp[ind] = true;
//         }

//         return dp[ind] = false;
//     }
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)
//             return true;
        
//         vector<int> dp(n, -1);
//         return jump(nums, dp, n, 0);
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //it shows at max what index can I reach.
        //initially I can only reach index 0, hence reach = 0
        int reach = 0; 
    
        for(int idx = 0; idx < nums.size(); idx++) {
            //at every index I'll check if my reach was atleast able to 
            //reach that particular index.
            
            //reach >= idx -> great, carry on. Otherwise, 
            if(reach < idx) return false;
            
            //now as you can reach this index, it's time to update your reach
            //as at every index, you're getting a new jump length.
            reach = max(reach, idx + nums[idx]);
        }
        
        //this means that you reached till the end of the array, wohooo!! 
        return true;
        
    }
};