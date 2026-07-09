class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;

        int i = 0;
        while(i < n && s[i] == ' ') i++;

        if(i == n || (s[i] != '-' && s[i] != '+' && s[i] < '0' && s[i] > '9')) return ans;

        int isneg = 1;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-') isneg = -1;
            i++;
        }
        while(i < n && s[i] == '0') i++;

        while(i < n){
            if(s[i] < '0' || s[i] > '9') break;

            int d = s[i] - '0';
            ans = ans * 10 + d;
            if (isneg * ans > INT_MAX) return INT_MAX;
            if (isneg * ans < INT_MIN) return INT_MIN;
            i++;
        }
        ans *= isneg;
        return ans;
    }
};