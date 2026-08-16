class Solution {
public:
    bool check(vector<int> v, int st, int n){
        int sum = st;
        v[st]--;
        for(int i = 1; i < n && v[st] >= 0; i++){
            if(sum % 3 == 1){
                if(v[1]){
                    v[1]--;
                    sum += 1;
                }
                else if(v[0]) v[0]--;
                else{
                    if(i % 2) return true;
                    break;
                }
            }
            else{
                if(v[2]){
                    v[2]--;
                    sum += 2;
                }
                else if(v[0]) v[0]--;
                else{
                    if(i % 2) return true;
                    break;
                }
            }
        }
        return false;
    }
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        
        vector<int> v(3,0);
        for(int i = 0; i < n; i++){
            v[stones[i] % 3]++;
        }

        bool start1 = check(v,1,n);
        bool start2 = check(v,2,n);

        if(start1 || start2) return true;
        return false;
    }
};