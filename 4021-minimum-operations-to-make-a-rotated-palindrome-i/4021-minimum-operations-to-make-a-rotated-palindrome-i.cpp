class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        s += s;
        int op = INT_MAX;
        for(int i = 0; i < n; i++){
            string s1 = s.substr(i,n);
            int l = 0, r = n - 1;
            int m = i;
            while(l < r){
                int a = abs(s1[r] - s1[l]);
                int b = abs(26 - a);
                m += min(a,b);
                l++;
                r--;
            }
            op = min(op, m);
        }
        return op;
    }
};