class Solution {
private:

    void Combinations(int index,vector<int>& candidates,int target,int sum,vector<int> v,vector<vector<int>> &ans){
        if(target == sum){
            ans.push_back(v);
            return ;
        }
        if(sum>target || index == candidates.size()) return ;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;

            sum += candidates[i];
            v.push_back(candidates[i]);
            Combinations(i+1,candidates,target,sum,v,ans);
            sum -= candidates[i];
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        vector<int> v;
        vector<vector<int>> ans;
        Combinations(0,candidates,target,sum,v,ans);
        return ans;
    }
};