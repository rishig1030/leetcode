bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second<b.second;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201,0);

        for(int i=0;i<nums.size();i++){
            freq[nums[i]+100]++;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<201;i++){
            if(freq[i])
            v.push_back({i-100,freq[i]});
        }

        sort(v.begin(),v.end(),comp);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            while(v[i].second--){
                ans.push_back(v[i].first);
            }
        }

        return ans;
    }
};