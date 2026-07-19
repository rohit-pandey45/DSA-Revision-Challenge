/**
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        stack<int> st;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (freq[s[i] - 'a'] == 1)
                st.push(i);
        }

        if (st.empty())
            return -1;

        return st.top();
    }
};
 */