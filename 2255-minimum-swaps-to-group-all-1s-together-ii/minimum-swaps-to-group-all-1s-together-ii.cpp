class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // using sliding window problem
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) count++;
        }
        nums.insert(nums.end(),nums.begin(),nums.end());
        
        int ans = nums.size();
        
        int one = 0;
        int i = 0;
        int r = 0;
        while(r<nums.size()){
            if(nums[r]==1) one++;

            if(r-i+1 == count){
               ans = min(ans,count-one);
               if(nums[i]==1) one--;
               i++; 
            }
            r++;
        }

        return ans==nums.size()?0:ans;
    }
};