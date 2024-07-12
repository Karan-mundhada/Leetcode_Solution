class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int>& memo)
    {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(memo[amount] != -2) return memo[amount];

        int mincoins = INT_MAX;
        for(int coin : coins)
        {
            int res = helper(coins, amount - coin, memo);
            if(res >= 0 && res < mincoins)
                mincoins = res + 1;
        }

        memo[amount] = (mincoins == INT_MAX) ? -1 : mincoins;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -2);
        return helper(coins, amount, memo);
    }
};