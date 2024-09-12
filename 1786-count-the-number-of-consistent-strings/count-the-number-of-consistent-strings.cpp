class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<int,int> mpp;
        for(int i=0;i<allowed.size();i++){
            mpp[allowed[i]]=1;
        }
        int count = 0;
        for(int i=0;i<words.size();i++){
            bool flag = true;
            for(int j=0;j<words[i].size();j++){
                if(mpp[words[i][j]]==0){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};