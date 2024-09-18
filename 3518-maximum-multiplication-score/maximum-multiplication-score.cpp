#define ll long long ;
class Solution {
private:
    long long find(int ia,int ib,vector<int>&a,vector<int>&b,vector<vector<long long>> &dp){
        if(ia==4) return 0;
        if(ib==b.size()) return -1e12;
        
        if(dp[ia][ib]!=(-1e12)) return dp[ia][ib];

        long long nt = find(ia,ib+1,a,b,dp);
        long long t = a[ia]*1ll*b[ib] + find(ia+1,ib+1,a,b,dp);

        return dp[ia][ib] = max(nt,t);
    }

public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        // 0,0 for indexes of a and b;
        // a and b for indexes of a and b;
        vector<vector<long long>> dp(4,vector<long long> (b.size(),-1e12));

        return find(0,0,a,b,dp);
    }
};