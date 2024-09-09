class Solution {


public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,-1));

        dp[m-1][n-1] = 1;
       
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(dp[i][j]==-1){
                    if(i+1<m && j+1<n)
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    else if(i+1<m){
                        dp[i][j] = dp[i+1][j];
                    }
                    else if(j+1<n) dp[i][j] = dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};