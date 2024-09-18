class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0;
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++)
        {
            string s = "";
            for(int j=0; j<n; j++)
            {
                s += to_string(grid[i][j]) + "--";
            }
            // cout<<1<<s<<endl;
            mp[s]++;
        }
        for(int i=0; i<n; i++)
        {
            string s = "";
            for(int j=0; j<n; j++)
            {
                s += to_string(grid[j][i]) + "--";
            }
            // cout<<2<<s<<endl;
            if(mp.find(s) != mp.end())
                cnt += mp[s];
        }

        return cnt;
    }
};