class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int bi=0;bi<32;bi++){
            int count = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] & (1<<bi)) count++;
            }
            if(count%3 == 1) n = n|(1<<bi);
        }
        return n;
    }   
};