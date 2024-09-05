class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean*(n+m);
        int sum1 = 0;
        for(int i=0;i<m;i++){
            sum1+=rolls[i];
        }

        int sum2 = total_sum-sum1;
        vector<int> ans;
        if(sum2<n || sum2>(n*6)) return ans;

        for(int i=0;i<n;i++){
            ans.push_back(6);
        }
        int ansSum = 6*n;
        int i = n-1;
        while(ansSum!=sum2){
            if(ans[i]==1) i--;
            ansSum--;
            ans[i]--;
            
        }
        return ans;
    }
};