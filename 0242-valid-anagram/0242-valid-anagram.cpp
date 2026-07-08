class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> fre(26,0);

        for(int i = 0; i < s.size(); i++){
            fre[s[i] - 'a']++;
            fre[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(fre[i]) return false;
        }
        return true;
    }
};