class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> mpp;

        mpp[0] = -1;
        int state= 0;
        int length = 0;
        
        for(int i=0;i<s.size();i++){
            char c = s[i];

            if(c=='a'){
                state ^= (1<<0);
            }
            else if(c=='e'){
                state ^= (1<<1);
            }
            else if(c=='i'){
                state ^= (1<<2);
            }
            else if(c=='o'){
                state^= (1<<3);
            }
            else if(c=='u'){
                state ^= (1<<4);
            }

            if (mpp.find(state) != mpp.end()) {
                length = max(length, i - mpp[state]);
            }
            else{
                mpp[state] = i;
            } 
        }
        return length;
    }
};