class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ']')
            {
                if(ans == 0)
                    ans++;
                else
                    ans--; 
            }
            else
                ans++;
        }

        return (ans + 1)/2;
    }
};