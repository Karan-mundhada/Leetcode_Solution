class Solution {
public:
    // void permut(vector<string>& ans, vector<int> vec, string curr)
    // {
    //     if(vec.empty())
    //     {
    //         ans.push_back(curr);
    //         return;
    //     }
    //     for(int i=0; i<vec.size(); i++)
    //     {
    //         curr += to_string(vec[i]);
    //         vector<int> temp = vec;
    //         vec.erase(vec.begin() + i);
    //         permut(ans, vec, curr);
    //         vec = temp;
    //         curr.pop_back();
    //     }
    // }
    string getPermutation(int n, int k) {
        vector<int> vec(n);
        int fac = 1; k--;
        for(int i = 1; i<n; i++)
        {
            vec[i-1] = i;
            fac *= i;
        }
        vec[n-1] = n;
        string ans = "";
        while(true)
        {
            int i = k / fac;
            ans += to_string(vec[i]);
            vec.erase(vec.begin() + i);
            if(vec.empty())
                break;
            
            k = k % fac;
            fac = fac / vec.size();
        }
        
        return ans;   
    }
};