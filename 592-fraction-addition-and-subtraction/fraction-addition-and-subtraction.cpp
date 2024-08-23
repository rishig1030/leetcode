class Solution {
    private:
        int gcd(int a,int b){
            int ans = 1;
            int i = 2;
            while(i<=min(abs(a),abs(b))){
                if(a%i==0 && b%i==0){
                    ans*=i;
                    a/=i;
                    b/=i;
                }
                else i++;
            }
            return ans;
        }
public:
    string fractionAddition(string s) {
        int numerator = 0;
        int denominator = 1;
        int i = 0;
        while(i<s.size()){
            int currNum = 0;
            int currDeno = 0;
            char sign = '+';
            if(s[i]=='-'){
                sign = '-';
                i++;
            }
            else if(s[i]=='+') i++;
            while(i<s.size() && s[i]!='/'){
                currNum = currNum*10 + (s[i]-'0');
                i++;
            }
            i++;
            while(i<s.size() && (s[i]>='0' && s[i]<='9')){
                currDeno = currDeno*10 + (s[i]-'0');
                i++;
            }
            if(sign=='-')
            numerator = numerator*currDeno - denominator*currNum;
            else numerator = numerator*currDeno + denominator*currNum;
            denominator = currDeno*denominator;

        }

        int GCD = gcd(numerator,denominator);
        numerator/=GCD;
        denominator/=GCD;

        if(numerator == 0) denominator = 1;
        string st = to_string(numerator) + "/" + to_string(denominator);
        return st;
    }
};