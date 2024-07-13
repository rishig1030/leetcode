class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0) return nums.size();
        int l = 0;
        int r = 1;
        int maxlen = 0;
        while(r<nums.size()){
            if(nums[r]<=nums[r-1]){
                l = r;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }

        return maxlen;
    }
};