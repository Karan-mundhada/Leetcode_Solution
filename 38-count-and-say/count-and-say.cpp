class Solution {
public:
    string rle(string c)
    {
        if(c == "1")
            return "11";

        string ret = "";
        char prev = c[0];
        int cnt = 1;
        for(int i=1; i<c.length(); i++)
        {
            if(prev != c[i])
            {
                ret += to_string(cnt);
                ret += prev;
                prev = c[i];
                cnt = 1;
            }
            else
                cnt++;
        }
        ret += to_string(cnt);
        ret += prev;
        return ret;
    }
    string countAndSay(int n) {
        if(n == 1)
            return "1";

        string cc = countAndSay(n - 1);
        cout<<rle("112331")<<endl;
        return rle(cc);
    }
};