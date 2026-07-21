/**
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        using T = tuple<int,int,int>;
        // {value, listIndex, elementIndex}

        priority_queue<T, vector<T>, greater<T>> pq;

        int currentMax = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int start = 0;
        int end = INT_MAX;

        while (pq.size() == nums.size()) {

            auto [value, row, col] = pq.top();
            pq.pop();

            if (currentMax - value < end - start) {
                start = value;
                end = currentMax;
            }

            if (col + 1 < nums[row].size()) {

                int nextValue = nums[row][col + 1];

                pq.push({nextValue, row, col + 1});

                currentMax = max(currentMax, nextValue);
            }
        }

        return {start, end};
    }
};
 */