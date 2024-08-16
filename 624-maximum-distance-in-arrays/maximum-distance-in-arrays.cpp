class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int s = arrays[0][0];
        int b = arrays[0].back();
        int diff = INT_MIN;
        for(int i=1; i<arrays.size(); i++)
        {
            diff = max(diff, abs(arrays[i].back() - s));
            diff = max(diff, abs(b - arrays[i][0]));
            s = min(s, arrays[i][0]);
            b = max(b, arrays[i].back());
        } 
        return diff;
    }
};