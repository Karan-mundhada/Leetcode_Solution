class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        int presum = nums[0];
        int minlen = 1000000;
        while(j < n && i < j)
        {
            if(presum >= target)
            {
                minlen = min(minlen, j - i);
                presum -= nums[i];
                cout<<i<<endl;
                i++;
            }
            else
            {
                presum += nums[j];
                cout<<j<<endl;
                j++;
            }
        }

        while(presum >= target && i < j)
        {
            minlen = min(minlen, j - i);
            presum -= nums[i];
            cout<<i<<endl;
            i++;
        }

        return minlen != 1000000 ? minlen : 0;
    }
};