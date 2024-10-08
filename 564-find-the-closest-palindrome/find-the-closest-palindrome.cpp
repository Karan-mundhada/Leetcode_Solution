class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.length(); 
        set<string> cand;

        if(s == "1") return "0";

        string pre = s.substr(0, (n + 1)/2);
        long long prenum = stoll(pre);

        for(long long i : {-1, 0, 1})
        {
            string new_pre = to_string(prenum + i);
            string candid;
            if(n % 2 == 0)
            {
                candid = new_pre + string(new_pre.rbegin(), new_pre.rend());
            }
            else
            {
                candid = new_pre + string(new_pre.rbegin() + 1, new_pre.rend());
            }
            cand.insert(candid);
        }

        cand.insert(to_string(static_cast<long long>(pow(10, n - 1)) - 1));
        cand.insert(to_string(static_cast<long long>(pow(10, n)) + 1));
        
        cand.erase(s);

        string closestPalindrome;
        long long minDifference = LLONG_MAX;
        long long num = stoll(s);
        for (const string& candidate : cand) {
            long long candidateNum = stoll(candidate);
            long long difference = abs(candidateNum - num);
            if (difference < minDifference || (difference == minDifference && candidateNum < stoll(closestPalindrome))) {
                minDifference = difference;
                closestPalindrome = candidate;
            }
        }

        return closestPalindrome;
    }
};