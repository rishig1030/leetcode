class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        vector<int> has(256,-1);
        while(r<s.size()){
            if(has[s[r]] != -1){
                if(has[s[r]]>=l){
                    l = has[s[r]] + 1;
                }
            }
            maxlen = max(maxlen,r-l+1);
            has[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};