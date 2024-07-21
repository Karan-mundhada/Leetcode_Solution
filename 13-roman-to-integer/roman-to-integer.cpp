class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        unordered_map<char, int> mp = {{' ', 0},{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

        char prev = ' ';
        for(char c : s)
        {
            if(mp[prev] < mp[c])
            {
                num = num + mp[c] - 2*mp[prev];
                prev = c;
            }
            else
            {
                num = num + mp[c];
                prev = c;
            }
            // cout<<num<<" "<<prev<<endl;
        }

        return num;
    }
};