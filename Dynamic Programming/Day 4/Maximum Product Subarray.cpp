/**
 class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        //Two Pointer
        //Calculating prefix and suffix sum
        int pref = 1;
        int suff = 1;
        int maxproduct = INT_MIN;
        for(int i = 0; i<n; i++){
            //if prefix-sum or suffix-sum  = 0 then reset it to 1 and store the maximum product upto that index 
            if(pref == 0){
                pref = 1;
            }
            if(suff == 0){
                suff = 1;
            }
            pref *= nums[i];
            suff *= nums[n-1-i];
            maxproduct = max(maxproduct,max(pref,suff));

        }
        return maxproduct;
    }
};
 */