class Solution {
private:
    bool isAlmostEqual(int a,int b){
    
        vector<pair<int,int>> v;

        while((a>0)||(b>0)){
            int ra = a%10;
            int rb = b%10;
            a/=10;
            b/=10;
            if(ra!=rb) {
                v.push_back({ra,rb});
                if(v.size()>2) return false;
            }
        }

        if(v.size()==1 || v.size()>2) return false;
        if(v.size()==0) return true;

        if((v[0].first == v[1].second )&& (v[0].second == v[1].first)) return true;
        return false;
        

    }

public:
    int countPairs(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(isAlmostEqual(nums[i],nums[j])){
                    count++;
                }
            }
        }        
        return count;
    }
};