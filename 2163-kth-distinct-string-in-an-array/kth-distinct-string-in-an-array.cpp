class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int count = 1;
        for(int i=0;i<arr.size();i++){
            if(k==count && mpp[arr[i]]==1){
                return arr[i];
            }
            else if(mpp[arr[i]] == 1) count++;
        }
        return "";
    }
};