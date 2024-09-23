class Solution {
public:
    unordered_map<string, int> mp;
    unordered_map<int, int> mem;

    int solve(string& s, int ind)
    {
        if(ind >= s.size())
            return 0;

        if(mem.find(ind) != mem.end())
            return mem[ind];

        int ext = INT_MAX;
        string temp = "";

        for(int i=ind; i<s.size(); i++)
        {
            temp += s[i];
            if(mp.find(temp) != mp.end())
            {
                ext = min(ext, solve(s, i + 1));
            }
        }

        ext = min(ext, 1 + solve(s, ind + 1));

        mem[ind] = ext;

        return mem[ind];
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto i : dictionary)
            mp[i]++;

        return solve(s, 0);
    }
};