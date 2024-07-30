class Solution {
public:
    int minimumDeletions(string s) {
        // optimized solution 
        int a_right =0 ;
        int a_left = 0;
        int b_right = 0;
        int b_left = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a') a_right++;
            else b_right++;
        }
        int ans = min(a_right,b_right);
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a') {
                a_right--;
                a_left++;
            }
            else{
                b_right--;
                b_left++;
            }
            ans = min(ans,a_right+b_left);
        }
        return ans;
    }
};