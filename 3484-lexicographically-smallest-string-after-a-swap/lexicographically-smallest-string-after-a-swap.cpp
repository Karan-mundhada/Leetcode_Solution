class Solution {
public:
    bool check(int i, int j)
    {
        if(i%2 == j%2 && i > j)
            return true;
        return false;
    }
    string getSmallestString(string s) {
        for(int i=1; i<s.length(); i++)
        {
            if(check(s[i-1] - 0, s[i] - 0))
            {
                char t = s[i-1];
                s[i-1] = s[i];
                s[i] = t;
                return s;
            }
        }

        return s;
    }
};