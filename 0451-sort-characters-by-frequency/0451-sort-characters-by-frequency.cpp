class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mp;

        for(int i = 0; i < n; i++) mp[s[i]]++;

        vector<pair<int,char>> v;

        for(auto it : mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());

        string ans;

        for(auto it : v){
            ans.append(it.first, it.second);
        }
        return ans;
    }
};