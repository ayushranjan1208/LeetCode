class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int mx = -1, mn = 101;

        for(auto e : nums){
            mx = max(mx,e);
            mn = min(mn,e);
        }

        vector<int> fre(mx - mn + 1);

        for(auto e : nums){
            fre[e - mn] ++;
        }

        vector<int> ans;

        for(int i = 0; i < fre.size(); i++){
            if(fre[i] == 0) ans.push_back(i + mn);
        }

        return ans;
    }
};