/**
 class Solution {
public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n);
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);

            int idx = it - temp.begin();
            if (it == temp.end())
                temp.push_back(nums[i]);
            else
                *it = nums[i];

            lis[i] = idx + 1;
        }

        return lis;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis = getLIS(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds = getLIS(nums);
        reverse(lds.begin(), lds.end());
        reverse(nums.begin(), nums.end());

        int longestMountain = 0;

        for (int i = 1; i < n - 1; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                longestMountain = max(longestMountain,
                                      lis[i] + lds[i] - 1);
            }
        }

        return n - longestMountain;
    }
};
 */