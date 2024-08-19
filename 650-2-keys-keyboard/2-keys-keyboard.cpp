class Solution {
public:
    int minSteps(int n) {
        // in this question dp[n] will represent the number of times required to get to n A;s
        vector<int> dp(1001);
        // initital base case;
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<n+1;i++){
            dp[i] = i; // i step is the maximum steps required to get to i A on the screen
            for(int j=2;j<i;j++){
                if(i%j==0){
                    // if j is the multiple of i
                    // then the step req will the 
                    // MIn step to get i/j A on screen + j number of A get
                    // 24 A req , 6 is the multiple 
                    // dp[24/4] + 6 ( 1 copy(whole) + 5 paste) 
                    dp[i] = min(dp[i],dp[i/j]+j);
                }
            }
        }
        return dp[n];
    }
};