class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum = 0;
        int rsum = 0;
        int sum = 0;
        for(int i=0;i<k;i++){
            lsum += arr[i];
        }
        sum = lsum;
        for(int i=0;i<k;i++){
            rsum += arr[arr.size()-1-i];
            lsum -= arr[k-i-1];
            sum = max(sum,lsum+rsum);
        }
        return sum;
    }
};