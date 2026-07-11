class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]] = 1;

        int sum = 0;
        for(auto &it : mp){
            sum += 1;
            it.second = sum;
        }
        int ans = INT_MAX;
        for(auto it : mp){
            int st = it.first, en = st + n - 1;

            auto y = mp.lower_bound(en + 1);
            y--;
            int range_sum = y->second - it.second + 1;
            int op = n - range_sum;

            ans = min(ans,op);
        }
        return ans;
    }
};