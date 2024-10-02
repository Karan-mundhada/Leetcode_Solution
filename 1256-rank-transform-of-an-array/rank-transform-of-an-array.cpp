class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int i : arr)
            mp[i]++;

        int cnt = 1;
        for(auto& [i, o] : mp)
        {
            // cout<<i<<cnt<<endl;
            o = cnt++;
        }

        for(int i=0; i<arr.size(); i++)
        {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};