class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> arr(26, 0);
        for(char c : allowed)
            arr[c-'a'] = 1;

        int cnt = 0;
        for(string d : words)
        {
            bool f = true;
            for(char c : d)
            {
                if(arr[c - 'a'] != 1)
                {
                    f = false;
                    break;
                }
            }
            if(f == true)
                cnt++;
        }
        
        return cnt;
    }
}; 