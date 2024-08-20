class Solution {
public:
    set<int> se;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        else if(se.find(n) != se.end())
            return false;
        se.insert(n);
        int s = 0;
        while(n > 0)
        {
            int g = n % 10;
            s += g * g;
            n = n/10;
        }
        return isHappy(s);
    }
};