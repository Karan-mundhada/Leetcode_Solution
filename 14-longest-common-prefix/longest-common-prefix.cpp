class Solution {
public:
    int check(string& comm, string s)
    {
        int i=0;
        string tem = "";
        // cout<<comm<<endl;
        while(i < s.length() && comm[i] == s[i])
        {
            tem += comm[i];
            i++;
        }
        comm = tem;
        // cout<<comm<<endl;
        return i;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string comm = strs[0];
        for(int i=1; i<strs.size(); i++)
        {
            if(check(comm, strs[i]) == 0)
                return "";
        }

        return comm;
    }
};