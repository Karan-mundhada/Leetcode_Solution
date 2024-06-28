class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cunt1 = 0, cunt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for(int i=0; i<n; i++)
        {
            if(cunt1 == 0 && nums[i] != ele2)
            {
                cunt1 = 1; ele1 = nums[i];
            }
            else if(cunt2 == 0 && nums[i] != ele1)
            {
                cunt2 = 1; ele2 = nums[i];
            }
            else if(nums[i] == ele1)
                cunt1++;
            else if(nums[i] == ele2)
                cunt2++;
            else
            {
                cunt1--;cunt2--;
            }
        }
        
        vector<int> ans;

        cunt1 = 0; cunt2 = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == ele1) cunt1++;
            if(nums[i] == ele2) cunt2++;
        }

        int m = (n / 3) + 1;
        if(cunt1 >= m) ans.push_back(ele1);
        if(cunt2 >= m) ans.push_back(ele2);

        sort(ans.begin(), ans.end());

        return ans;
    }
};