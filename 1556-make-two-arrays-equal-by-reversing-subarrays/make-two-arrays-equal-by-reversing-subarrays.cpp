class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<target.size();i++){
            if(mpp[target[i]]==0) return false;
            mpp[target[i]]--;
        }
        return true;
    }
};