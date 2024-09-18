bool custComp(long long a,long long b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    return (s1+s2)>(s2+s1);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        sort(nums.begin(),nums.end(),custComp);

        for(int i=0;i<nums.size();i++){
            s+= to_string(nums[i]);
        }
        if(s[0] == '0') return "0";
        return s;
    }
};