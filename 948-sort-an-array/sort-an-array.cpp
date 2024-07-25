class Solution {
private:
    void merge(vector<int> &nums,int i,int mid,int n){
        int left = i;
        int right = mid+1;
        vector<int> v;
        while(left<=mid && right<=n){
            if(nums[left]<nums[right]){
                v.push_back(nums[left++]);
            }
            else v.push_back(nums[right++]);
        }
        while(left<=mid) v.push_back(nums[left++]);
        while(right<=n) v.push_back(nums[right++]);

        for(int j=i;j<=n;j++){
            nums[j] = v[j-i];
        }
    }

    void mergesort(vector<int> &nums,int i,int n){
        if(i==n) return;
        int mid = (i+n)/2;
        mergesort(nums,i,mid);
        mergesort(nums,mid+1,n);
        merge(nums,i,mid,n);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};