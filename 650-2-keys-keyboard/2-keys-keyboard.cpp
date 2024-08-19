class Solution {
public:
    int minSteps(int n) {
        int c = 1;
        int scr = 1;
        int cnt = 0;
        while(n != scr)
        {
            if(cnt == 0)
            {
                cnt += 2;
                scr += c;
            }
            else
            {
                cnt++;
                scr += c;
            }
            if(n % scr == 0 && n != scr)
            {
                cnt++;
                c = scr;
            }
        }

        return cnt;
    }
};