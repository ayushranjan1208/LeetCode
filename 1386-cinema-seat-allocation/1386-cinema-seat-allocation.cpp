class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,vector<int>> mp;
        for(auto &r : reservedSeats){
            mp[r[0]].push_back(r[1]);
        }

        int ans = n * 2;

        for(auto it : mp){
            vector<int> v(11, 0);
            for(auto i : it.second){
                v[i] = 1;
            }
            int s = 0, c = 0;
            for(int j = 2; j <= 8; j++){
                if(j <= 5){
                    s += v[j];
                }
                else{
                    s += v[j] + v[j + 1];
                    s -= v[j - 4] + v[j - 3];
                    j++;
                }
                if(j >= 5){
                    if(s == 0) c++;
                }
            }

            if(c < 3){
                if(c) ans--;
                else ans -= 2;
            }
        }

        return ans;
    }
};