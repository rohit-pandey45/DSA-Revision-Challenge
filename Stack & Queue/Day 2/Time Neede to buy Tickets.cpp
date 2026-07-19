/**
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            q.push({tickets[i],i});
        }
        int time = 0;
        while(!q.empty()){
            auto[t,ind] = q.front();
            q.pop();
            t--;
            time++;
            if(t == 0 & ind == k){
                return time;
            }
            if(t > 0){
                q.push({t,ind});
            }
        }
        return time;
    }
};
 */