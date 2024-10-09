class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnto = 0, cntc = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                cnto++;
            }
            else
            {
                if(cnto <= 0)
                    cntc++;
                else
                    cnto--;
            }
        }

        return abs(cnto) + abs(cntc);
    }
};