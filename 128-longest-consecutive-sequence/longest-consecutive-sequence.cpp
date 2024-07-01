class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        int mc = 0, c = 0;
        int ele = INT_MIN;
        for(auto i=mp.begin(); i!=mp.end(); i++)
        {
            if(ele == INT_MIN)
            {
                ele = i->first;
                c++;
            }
            else
            {
                if(ele+1 == i->first)
                    c++;
                else
                {
                    mc = max(mc, c);
                    c = 1;
                }
                ele = i->first;
            }
            mc = max(mc, c);
        }

        return mc;
    }
};