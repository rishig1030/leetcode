class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int number = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(i!=s.size()-1 && mpp[s[i+1]]>mpp[s[i]]){
                number -= mpp[s[i]];
            }
            else number += mpp[s[i]];
        }
        return number;
    }
};