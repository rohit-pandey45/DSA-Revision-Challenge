//Tabulation Approach
#include <bits/stdc++.h>
using namespace std; 


int branch_and_bound(int n, int wmax, vector<pair<int,int>> items) {
    vector<vector<int>> dp(n, vector<int> (wmax+1,0));
    
    //BASE CASE
    for(int w = items[0].first; w <= wmax; w++){
        dp[0][w] = items[0].second;
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= wmax; w++){
            int notTake = dp[ind-1][w];
            int take = INT_MIN;
            if(items[ind].first <= w){
                take = items[ind].second + dp[ind-1][w - items[ind].first];
            }
            dp[ind][w] = max(take,notTake);
        }
    }
    return dp[n-1][wmax];
}

int main() {
    int n; cin >> n;
    int wmax; cin >> wmax;
    vector<pair<int,int>> items(n);
    for(int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    cout << branch_and_bound(n, wmax, items);

    return 0;
}


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