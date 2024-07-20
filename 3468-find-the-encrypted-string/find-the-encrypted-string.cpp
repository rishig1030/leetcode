class Solution {
public:
    string getEncryptedString(string s, int k) {
        string v = s;
        for(int i=0;i<s.size();i++){
            s[i] = v[(i+k)%s.size()];
        }
        return s;
    }
};