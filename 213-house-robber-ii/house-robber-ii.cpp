class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int a = 0;
        int b = nums[1];
        for(int i=2;i<nums.size();i++){
            int take = nums[i]+a;
            int nottake = b;
            a = b;
            b = max(take,nottake);
        }
        int a1 = 0;
        int b1 = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            int take = nums[i]+a1;
            int nottake = b1;
            a1 = b1;
            b1 = max(take,nottake);
        }
        return max(b,b1);
    }
};