class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }
            else if(bills[i] == 20){
                if(ten && five){
                    ten--;
                    five--;
                    twenty++;
                }
                else if(five >=3){
                    five-=3;
                    twenty++;
                }
                else return false;
            }
        }

        return true;
    }
};