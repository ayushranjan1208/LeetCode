class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){

            vector<int> fre(26,0);
            for(int j = i; j < n; j++){
                fre[s[j] - 'a']++;

                int mini = INT_MAX, maxi = INT_MIN;

                for(int k = 0; k < 26; k++){
                    if(fre[k] == 0) continue;
                    mini = min(mini,fre[k]);
                    maxi = max(maxi,fre[k]);
                }

                ans += maxi - mini;
            }
        }
        return ans;
    }
};