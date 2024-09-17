class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mpp;
        vector<string> ans;
        for(int i=0;i<s1.size();i++){
            string word = "";
            while(i<s1.size() && s1[i]!=' '){
                word+=s1[i];
                i++;
            }
            mpp[word]++;
        }

        for(int i=0;i<s2.size();i++){
            string word = "";
            while(i<s2.size() && s2[i]!=' '){
                word+=s2[i];
                i++;
            }
            mpp[word]++;
        }

        for(auto it:mpp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};