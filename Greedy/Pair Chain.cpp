/**
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<pair<int,int>> chain;
        for(auto& it : pairs){
            int start = it.front();
            int end = it.back();
            chain.push_back({end,start});
        }
        sort(chain.begin(),chain.end());
        int cnt = 1;
        int b = chain[0].first;
        for(int i = 0; i<n; i++){
            int c = chain[i].second;
            if(c > b){
                cnt++;
                b = chain[i].first;
            }
        }
        return cnt;
    }
};
 */