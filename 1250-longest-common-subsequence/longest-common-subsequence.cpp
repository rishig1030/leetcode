
class Solution {
private:
    
    
    // int f(int a,int b,string text1,string text2,vector<vector<int>> &dp){
    //     if(a<0 || b<0) return 0;

    //     if(dp[a][b]!=-1) return dp[a][b];

    //     if(text1[a]==text2[b]){
    //         return dp[a][b] = 1+f(a-1,b-1,text1,text2,dp);
    //     }
        
    //     return dp[a][b] = max(f(a-1,b,text1,text2,dp),f(a,b-1,text1,text2,dp)); 
    // }   

public:
    int longestCommonSubsequence(string text1, string text2) {
        // to find the longest subsequence 

        int a = text1.size();
        int b = text2.size();
        //vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        // memoization ,some test cases are not ruunning ;-return f(a-1,b-1,text1,text2,dp);

        // using tabulation , in order to remove auxillary stack space
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // base case is dp[-1][n] || dp[m][-1] == -1 
        // so we used shifting operator
        for(int i=0;i<=a;i++) dp[i][0] = 0;
        for(int i=0;i<=b;i++) dp[0][i] = 0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[a][b];
    }
};