class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        
        for(int i=0;i<colors.size();i++){
            if(i==0){
                if(colors[colors.size()-1] == colors[1] && colors[1]!= colors[0]){
                    count++;
                }
            }
            else if(i==colors.size()-1){
                if(colors[colors.size()-2] == colors[0] && colors[colors.size()-1]!= colors[colors.size()-2]) count++;
            }
            else{
                if(colors[i+1] == colors[i-1] && colors[i] != colors[i+1]) count++;
            }
        }

        return count;
    }
};