/**
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;     //mpp[value,frequency]
        mpp[0] = 1;
        int count = 0;
        int presum = 0;
        for(int i = 0; i<n; i++){
            presum = presum + nums[i];      //Calculating running sum
            int more = presum - k;
            count += mpp[more];
            mpp[presum] += 1;
        }
        return count;

    }
};
 */