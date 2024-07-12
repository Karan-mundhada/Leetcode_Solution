class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int n = g.size(), m = s.size();
        int child = 0;

        while(i < n && j < m)
        {
            if(s[j] < g[i])
                j++;
            else if(s[j] >= g[i])
            {
                i++; j++;
                child++;
            }
        }

        return child;
    }
};