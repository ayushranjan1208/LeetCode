class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        if(m < n) return false;
        if(n == 1) return true;

        vector<int> pre(n,-1);
        vector<int> suf(n,-1);

        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                pre[i] = j;
                i++;
            }
            j++;
        }
        i = n - 1, j = m - 1;

        while(i >= 0 && j >= 0){
            if(s[i] == t[j]){
                suf[i] = j;
                i--;
            }
            j--;
        }

        if(suf[1] > 0 || (pre[n-2] < m - 1 && pre[n-2] != -1)) return true;

        for(int i = 1; i < n - 1; i++){
            int l = pre[i - 1], r = suf[i + 1];

            if(r - l >= 2 && r != -1 && l != -1) return true;
        }
        return false;
    }
};