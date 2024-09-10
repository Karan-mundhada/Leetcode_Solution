class Solution {
public:
    bool isvow(char c)
    {
        vector<char> arr = {'a', 'e', 'i', 'o', 'u'};
        for(char i : arr)
        {
            if(i == c)
                return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int cnt = 0;
        int f = 0;
        for(int i=0; i<k; i++)
        {
            if(isvow(s[i]))
                cnt++;
        }
        int maxcnt = cnt;
        for(int i=k; i<n; i++)
        {
            cnt += isvow(s[i]) - isvow(s[f++]);
            maxcnt = max(maxcnt, cnt);
            if(maxcnt == k)
                break;
        }
        return maxcnt;
    }
};