class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];

            int need = sum - k;

            if(mp.count(need)) ans += mp[need];
            mp[sum]++;
        }
        return ans;
    }
};