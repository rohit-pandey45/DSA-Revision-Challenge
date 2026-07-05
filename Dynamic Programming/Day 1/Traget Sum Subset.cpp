//Tabulation Approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = notTaken || taken;
            }
        }
        return dp[n - 1][k];
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}


/**
//Memoisation

class Solution {
public:
    int solve(int ind, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int totalSum) {
        //BASE CASE
        if (ind < 0){
            return (sum == target);
        }
        if (dp[ind][sum + totalSum] != -1){
            return dp[ind][sum + totalSum];
        }
        int plus = solve(ind - 1, sum + nums[ind], nums, target, dp, totalSum);
        int minus = solve(ind - 1, sum - nums[ind], nums, target, dp, totalSum);

        return dp[ind][sum + totalSum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int> (2*totalSum+1,-1));
        int ans = solve(n-1, 0, nums, target, dp, totalSum);
        return ans;
    }
};
 */