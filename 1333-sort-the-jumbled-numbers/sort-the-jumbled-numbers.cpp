
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            string st = "";
            int a = nums[i];
            if(a==0) {
                char ch = '0'+mapping[a] ;
                st += ch;
            }
            while(a){
                int s = a%10;
                char ch = '0'+mapping[s] ;
                st += ch;
                a/=10;
            }   
            reverse(st.begin(),st.end());
            int convert = stoi(st);
            v.push_back(convert);
        }

        vector<pair<int,int>> ans;

        for(int i=0;i<v.size();i++){
            ans.push_back({v[i],i});
        }

        sort(ans.begin(),ans.end());

        for(int i=0;i<nums.size();i++){
            v[i] = nums[ans[i].second];
        }
        return v;
    }
};