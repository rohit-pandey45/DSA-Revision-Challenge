/**
Memoisation Approach

class Solution {
public:
    int findMinCoins(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        //BASE CASE
        if (ind == 0) {
            if (target % coins[0] == 0){
                return target / coins[0];
            }
            return 1e9;
        }

        //DP Approach
        if (dp[ind][target] != -1){
            return dp[ind][target];
        }

        int notTake = findMinCoins(ind - 1, target, coins, dp);

        int take = 1e9;
        if (coins[ind] <= target)
            take = 1 + findMinCoins(ind, target - coins[ind], coins, dp);

        return dp[ind][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = findMinCoins(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
 */