class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;

        int i = 0;
        while(true){
            if(strs[0].size() == i) break;
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j].size() == i){
                    return ans;
                }
                if(ch != strs[j][i]) return ans;
            }
            ans.push_back(ch);
            i++;
        }
        return ans;
    }
};