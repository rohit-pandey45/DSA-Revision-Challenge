/**
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2  = nums2.size();
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int i = n2-1; i >= 0; i--){
            int ele = nums2[i];
            while(!st.empty() && st.top() < ele){
                st.pop();
            }
            mpp[ele] = st.empty() ? -1 : st.top();
            st.push(ele);
        }
        vector<int> ans;
        for(int i = 0; i<n1; i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};
 */