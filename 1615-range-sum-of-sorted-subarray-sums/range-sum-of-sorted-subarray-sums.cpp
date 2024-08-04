int mod = 1000000007;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int l = 0;
        int r = 0;
        vector<int> v;
        while(l<n){
            int k = l;
            int sum = 0;
            while(k<=r){
                sum = (sum+nums[k])%mod;
                k++;
            }
            r++;
            if(r==n){
                l++;
                r=l;
            }
            v.push_back(sum%mod);
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=left-1;i<right;i++){
            ans = (ans+v[i])%mod;
        }
        return ans;
    }
};