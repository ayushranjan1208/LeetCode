class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<int> lastInd(26,0);
        vector<bool> used(26,0);

        for(int i = 0; i < n; i++) lastInd[s[i] - 'a'] = i;

        string ans;
        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(used[ch - 'a']) continue;

            while(!ans.empty() && ans.back() > ch && lastInd[ans.back() - 'a'] > i){
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            used[ch - 'a'] = true;
            ans.push_back(ch);
        }
        return ans;
    }
};