class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0;
        bool flag = true;
        for(int i=0;i<haystack.size();i++){
            flag = true;
            if(needle[l]==haystack[i]){
                for(int j=l;j<needle.size();j++){
                    if(needle[j]!=haystack[i+j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return i;
            }
        }
        return -1;
    }
};