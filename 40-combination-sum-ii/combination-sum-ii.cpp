class Solution {
public:
    void help(vector<vector<int>>& ans, vector<int>& candi, vector<int> pp, int target, int ind)
    {
        if(target == 0)
        {
            ans.push_back(pp);
            return;
        }
        else if(ind >= candi.size() || target < candi[ind])
            return;
        else if(target > 0)
        {
            for(int i=ind; i<candi.size(); i++)
            {
                if(i != ind && candi[i] == candi[i-1]) continue;
                target -= candi[i];
                pp.push_back(candi[i]);
                help(ans, candi, pp, target, i+1);
                pp.pop_back();
                target += candi[i];
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> pp;
        help(ans, candidates, pp, target, 0);
        return ans;
    }
};