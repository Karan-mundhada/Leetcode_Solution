class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;

        unordered_set<int> st;
        int mx = 0, l = 0;

        for(int r=0; r<n; r++)
        {
            if(st.find(s[r]) != st.end())
            {
                while(l < r && st.find(s[r]) != st.end())
                {
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};

// Legacy code 
//I hardly understand it anymore
//my best guess is i was erasing all the prev elements in map by calculating distance between two pointers

// int ans = 0;
// if(s.length() == 0)
// {
//     return ans;
// }
// unordered_map<char, int> m;
// int i = 0, j = 0; 
// while(j<s.length())
// {
//     m[s[j]]++;
//     if(m.size() == j-i+1)
//     {
//         ans = max(ans, j-i+1);
//     }
//     else
//     {
//         while(m.size()<j-i+1)
//         {
//             m[s[i]]--;
//             if(m[s[i]] == 0)
//             {
//                 m.erase(s[i]);
//             }
//             i++;
//         }
//     }
//     j++;
// }
// return ans;