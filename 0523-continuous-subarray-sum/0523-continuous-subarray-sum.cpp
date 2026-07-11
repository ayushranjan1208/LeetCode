class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int mod = sum % k;
            if(i > 0 && mod == 0) return true;
            if(mp.count(mod)){
                if(i - mp[mod] >= 2) return true;
            }
            else mp[mod] = i;
        }
        return false;
    }
};