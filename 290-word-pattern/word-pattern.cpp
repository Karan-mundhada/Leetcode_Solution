// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//         unordered_map<char, string> mp;
//         unordered_map<string, char> mp2;
//         int i = 0;
//         for(char c : pattern)
//         {
//             string t = "" + to_string(s[i]);
//             while(s[i] != ' ' && i < s.length())
//             {
//                 t += s[i];
//                 i++;
//             }
//             i++;
//             if(mp.find(c) == mp.end() && mp2.find(t) == mp2.end())
//             {
//                 mp[c] = t;
//                 mp2[t] = c;
//             }
//             else if(mp[c] != t)
//                 return false;
//             else if(mp2[t] != c)
//                 return false;
//         }
//         if(i < s.length()) return false;
//         return true;
//     }
// };

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);
        string word;
        unordered_map<string,char>mpp1;
        unordered_map<char,char>mpp2;
        
        string s1,s2;

        char i = 'a';

        while(ss >> word)
        {
            if(mpp1.find(word) == mpp1.end()) mpp1[word] = i++;
            
            s1.push_back(mpp1[word]);     
        }

        i = 'a';

        for(auto &it : pattern)
        {
            if(mpp2.find(it) == mpp2.end()) mpp2[it] = i++;
        
            s2.push_back(mpp2[it]);
        }

        if(s1!=s2) return false;


        return true;
    }
};
