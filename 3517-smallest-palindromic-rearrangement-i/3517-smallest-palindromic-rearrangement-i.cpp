class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> fre(26,0);
        for(int i = 0; i < n; i++) fre[s[i] - 'a']++;

        string ans = s;
        int i = 0, j = n - 1;
        for(int k = 0; k < 26; k++){
            while(fre[k] >= 2){
                ans[i] = 'a' + k;
                ans[j] = 'a' + k;
                i++;
                j--;
                fre[k] -= 2;
            }
        }

        return ans;
    }
};