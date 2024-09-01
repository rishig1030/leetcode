bool custComp(pair<int,int> a, pair<int,int> b){
    
    return (double(a.first)/double(a.second))>(double(b.first)/double(b.second));
}

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long total_damage = 0;
        for(int i=0;i<damage.size();i++){
            total_damage+=damage[i];
        }

        vector<pair<int,int>> v(damage.size());
        for(int i=0;i<damage.size();i++){
            int time = health[i]/power;
            if((health[i]%power) != 0) time++;
            v[i] = {damage[i],time};
        }
        long long minimum  = 0;
        sort(v.begin(),v.end(),custComp);
        for(int i=0;i<damage.size();i++){
            minimum+= total_damage*v[i].second;
            total_damage-=v[i].first;
        }
        return minimum;

    }
};