class Solution {
public:
    int fun(string &s, int i,long long ans,int sign){
        if(i >= s.size() || !isdigit(s[i])){
            return sign*ans;
        }

        ans = ans * 10 + s[i] - '0';

        if(sign * ans > INT_MAX) return INT_MAX;
        if(sign * ans < INT_MIN) return INT_MIN;

        return fun(s,i+1,ans,sign);
    }
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
        return fun(s,i,ans,isneg);
    }
};