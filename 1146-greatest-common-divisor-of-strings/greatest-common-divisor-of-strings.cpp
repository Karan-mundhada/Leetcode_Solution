class Solution {
public:
    bool check(string s1, string s2)
    {
        int h = s1.length()/s2.length();
        string temp = s2;
        for(int i=1; i<h; i++)
        {
            s2 += temp;
        } 
        // cout<<s2<<endl;
        return (s1 == s2);

    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        if(n1 < n2) return gcdOfStrings(str2, str1);

        string ans = "";
        string gstring = "";
        for(int i=0; i<n2; i++)
        {
            ans += str2[i];
            
            if(check(str2, ans) && check(str1, ans))
                gstring = ans;
        }

        return gstring;
    }
};