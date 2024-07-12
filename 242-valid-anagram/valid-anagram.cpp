class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mpp;
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            
            if(mpp[t[i]] == 0) return false;
            else mpp[t[i]]--;
        }
        return true;
    }
};