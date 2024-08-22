class Solution {
public:
    int findComplement(int num) {
        string s = "";
        while(num){
            if(num==1){
                s+='0';
                break;
            }
            else if(num%2==0){
                s+='1';
            }
            else s+='0';
            num/=2;
        }
        int result = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                result += pow(2,i);
            }
        }
        return result;

    }
};