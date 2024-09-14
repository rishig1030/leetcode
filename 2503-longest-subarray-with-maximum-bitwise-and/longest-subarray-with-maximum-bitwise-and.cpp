class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // AND of two equal number will always be equal
        // AND of bigger number and smaller number will always be lesser than the bigger number

        // so we will only extend our subarray if the numbers are equal
        // if forward number is greater than curr MaXAND , we will ignore the prev number and move forward

        // question is now simple to find the max- value , and the length of subaray which contains onyl simsilar element
        int maxE = 0;
        for(int i=0;i<nums.size();i++){
            maxE = max(maxE,nums[i]);
        }

        int maxLen = 0;
        int len = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxE){
                while(i<nums.size() && nums[i]==maxE){
                    i++;
                    len++;
                }
                maxLen = max(maxLen,len);
                len = 0;
            }
        }
        return maxLen;
    }
};