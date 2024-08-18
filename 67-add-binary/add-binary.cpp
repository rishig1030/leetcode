class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        string s = "";
        char carry = '0';
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1' && carry =='1'){
                s += '1';
                carry = '1';
            }
            else if(a[i]=='1' && b[j]=='1'){
                s+='0';
                carry = '1';
            }
            else if(a[i]=='1' && carry=='1'){
                s+= '0';
                carry  = '1';
            }
            else if(b[j]=='1' && carry=='1'){
                s+='0';
                carry = '1';
            }
            else if(a[i]=='0' && b[j]=='0' && carry =='0'){
                s+='0';
                carry = '0';
            }
            else{
                s+='1';
                carry ='0';
            }
            i--;
            j--;
        }

        while(j>=0){
            if(b[j]=='1' && carry=='1'){
                carry = '1';
                s+='0';
            }
            else if(carry=='0'){
                s+=b[j];
            }
            else{
                s+=carry;
                carry = '0';
            }
            j--;
        }
       
        while(i>=0){
            if(a[i]=='1' && carry=='1'){
                s+='0';
                carry = '1';
            }
            else if(carry=='0'){
                s+=a[i];
            }
            else {
                s+=carry;
                carry = '0';
            }
            i--;
        }
        if(carry=='1') s+='1';
        reverse(s.begin(),s.end());
        return s;
    }
};