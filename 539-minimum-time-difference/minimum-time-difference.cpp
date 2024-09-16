class Solution {
public:
    int convert(string f)
    {
        int h = (f[0] - '0')*10 + f[1] - '0';
        int m = (f[3] - '0')*10 + f[4] - '0';
        return h*60 + m;
    }
    int findMinDifference(vector<string>& tp) {
        int toth = 1440;
        int n = tp.size();
        int mindiff = INT_MAX;

        vector<int> mint(n);
        for(int i=0; i<n; i++)
        {
            mint[i] = convert(tp[i]);
        }
        sort(mint.begin(), mint.end());
        for(int j=0; j<n-1; j++)
        {
            mindiff = min(mindiff, mint[j+1] - mint[j]);
        }

        mindiff = min(mindiff, toth - mint[n-1] + mint[0]);

        return mindiff;
    }
};