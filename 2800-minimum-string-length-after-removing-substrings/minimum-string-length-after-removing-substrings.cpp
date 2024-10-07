class Solution {
public:
    int minLength(string s) {
        if(s == "" || s.length() == 1)
            return s.length();

        stack<char> ss;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'B' && !ss.empty() && ss.top() == 'A')
            {
                ss.pop();
                continue;
            }
            else if(s[i] == 'D' && !ss.empty() && ss.top() == 'C')
            {
                ss.pop();
                continue;
            }
            else
                ss.push(s[i]);
        }

        return ss.size();
    }
};