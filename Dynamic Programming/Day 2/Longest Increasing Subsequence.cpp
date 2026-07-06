/**
class Solution {
public:
    int func(int i, int prevInd, vector<vector<int>>& dp, vector<int>& arr) {
        // Base Case
        if (i == arr.size())
            return 0;
        // Memoization
        if (dp[i][prevInd + 1] != -1)
            return dp[i][prevInd + 1];
        int notTake = func(i + 1, prevInd, dp, arr);
        int take = 0;
        if (prevInd == -1 || arr[i] > arr[prevInd]) {
            take = 1 + func(i + 1, i, dp, arr);
        }
        return dp[i][prevInd + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return func(0, -1, dp, nums);
    }
};
 */