class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l = 0;
        int r = 0;
        int  count = 0;
        while(l<g.size() && r<s.size()){
            if(s[r] >= g[l]){
                count++;
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return count;
    }
};