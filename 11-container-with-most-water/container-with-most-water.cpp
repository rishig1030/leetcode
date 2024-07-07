class Solution {
public:
    int maxArea(vector<int>& arr) {
        // int area = 0;
        // for(int i=0;i<height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         area = max(area, min(height[i],height[j])*(j-i));
        //     }
        // }
        // return area;
        // time complexity is O(N2) , hence not accepted

        // using two pointer approach
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int area = 0;
        while(left<right){
            if(arr[left]<arr[right]){
                area = max(area,arr[left]*(right-left));
                left++;
            }
            else {
                area = max(area,arr[right]*(right-left));
                right--;
            }
        }
        return area;

    }
};