class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ans = 0;
        int maxZero = 0;
        int last = 0, cur = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(cur){
                    last = cur;
                    cur = 0;
                }
                ans++;
                continue;
            }
            else{
                cur++;
            }
            if(last) maxZero = max(maxZero, last + cur);
        }
        return ans + maxZero;
    }
};