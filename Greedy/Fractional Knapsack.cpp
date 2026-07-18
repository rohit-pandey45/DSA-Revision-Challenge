/**
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double,pair<int,int>>> items;
        for(int i = 0; i<n; i++){
            double ratio = (double)val[i]/wt[i];
            items.push_back({ratio,{val[i],wt[i]}});
        }
        
        sort(items.begin(),items.end(),greater<>());
        double maxVal = 0.0;
        for(auto& it : items){
            int value = it.second.first;
            int weight = it.second.second;
            
            if(capacity >= weight){
                maxVal += value;
                capacity -= weight;
            }
            else{
                maxVal += it.first*capacity; 
                break;
            }
        }
        return maxVal;
    }
};

 */