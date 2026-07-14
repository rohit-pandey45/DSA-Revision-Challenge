/**
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (auto &row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        int repeated = 0, missing = 0;

        // Find repeated and missing numbers
        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 2)
                repeated = i;
            else if (freq[i] == 0)
                missing = i;
        }

        return {repeated, missing};
    }
};
 */