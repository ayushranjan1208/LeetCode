class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'I') ans += 1;
            else if(s[i] == 'V') ans += 5;
            else if(s[i] == 'X') ans += 10;
            else if(s[i] == 'L') ans += 50;
            else if(s[i] == 'C') ans += 100;
            else if(s[i] == 'D') ans += 500;
            else ans += 1000;

            if(i == 0) continue;

            if(s[i] == 'V' && s[i-1] == 'I') ans -= 2;
            else if(s[i] == 'X' && s[i-1] == 'I') ans -= 2;
            else if(s[i] == 'L' && s[i-1] == 'X') ans -= 20;
            else if(s[i] == 'C' && s[i-1] == 'X') ans -= 20;
            else if(s[i] == 'D' && s[i-1] == 'C') ans -= 200;
            else if(s[i] == 'M' && s[i-1] == 'C') ans -= 200;
        }
        return ans;
    }
};