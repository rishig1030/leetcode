class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        long long  prev = nums[0];
        long long  prevIndex =  0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>=prev){
                ans+=(i-prevIndex)*prev;
                prev = nums[i];
                prevIndex = i;
            }
        }
        ans+= (nums.size()-1-prevIndex)*prev;
        return ans; 
    }
};