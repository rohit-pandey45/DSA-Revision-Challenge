/**
Memoisation Approach

class Solution {
  public:
    int solve(int ind, int W, vector<vector<int>>& dp, vector<int> &val, vector<int> &wt){
        //BASE CASE
        if(ind == 0){
            if(wt[0] <= W){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        //DP Approach
        if(dp[ind][W] != -1)    return dp[ind][W];
        
        int notTake = solve(ind-1,W,dp,val,wt);
        int take = INT_MIN;
        if(wt[ind] <= W){
            take = val[ind] + solve(ind-1,W-wt[ind],dp,val,wt);
        }
        return dp[ind][W] = max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (W+1,-1));
        int ans = solve(n-1,W,dp,val,wt);
        return ans;
        
        
    }
};

 */