/**
class Solution {
public:
    string removeOccurrences(string s, string part) {
        //string::npos --> means NOT FOUND
        while (s.find(part) != string::npos) {
            int pos = s.find(part); //Returns index of the starting of the substring
            s.erase(pos, part.size());
        }

        return s;
    }
};
 */