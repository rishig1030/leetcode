class Solution {
public:
    int getLucky(string s, int k) {
        string st="";
        int num = 0;
        for(int i=0;i<s.size();i++){
            st+=to_string(s[i]-'a'+1);
        }
        while(k--){
            num = 0;
            for(int i=0;i<st.size();i++){
                num = num + (st[i]-'0');
            }
            st = to_string(num);
        }
        return num;
    }
};