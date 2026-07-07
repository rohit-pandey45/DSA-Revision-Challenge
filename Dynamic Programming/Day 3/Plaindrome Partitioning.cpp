/**
 class Solution {
public: 
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int index, string& s){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = index; i<s.size(); i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(i+1,s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
    }
};
 */