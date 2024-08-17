class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B' && st.size()!=0 && st.top()=='A'){
                st.pop();
            }
            else if(s[i]=='D' && st.size()!=0 && st.top()=='C'){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.size();
    }
};