class Solution {
public:
    bool ispal(string str, int l)
    {
        if(l == 1)
            return true;
        else
        {
            int r = 0; l--;
            while(r <= l)
            {
                if(str[r] != str[l])
                    return false;
                r++; l--;
            }
        }
        return true;
    }
    void back(vector<vector<string>>& ans, vector<string> curr, string s, int ind, int n)
    {
        if(ind >= n)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=ind; i<n; i++)
        {
            string f = s.substr(ind, i-ind+1);
            if(ispal(f, i-ind+1))
            {
                curr.push_back(f);
                back(ans, curr, s, i+1, n);
                curr.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        back(ans, curr, s, 0, s.length());
        return ans;
    }
};