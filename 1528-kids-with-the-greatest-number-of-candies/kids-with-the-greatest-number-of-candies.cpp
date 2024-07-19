class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n, false);
        int maxcand = 0;
        for(int can : candies)
        {
            if(maxcand < can)
                maxcand = can;
        }

        for(int i=0; i<n; i++)
        {
            if(candies[i] + extraCandies >= maxcand)
                result[i] = true;
        }

        return result;
    }
};