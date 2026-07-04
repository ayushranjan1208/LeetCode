class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()) continue;

            int pre = 0, f1 = false;
            if(mp.find(nums[i] - 1) != mp.end()){
                pre = mp[nums[i] - 1];
                f1 = true;
            }

            int nxt = 0, f2 = false;
            if(mp.find(nums[i] + 1) != mp.end()){
                nxt = mp[nums[i] + 1];
                f2 = true;
            }
            int len = 1 + pre + nxt;
            mp[nums[i]] = len;
            if(f1) mp[nums[i] - pre] = len;
            if(f2) mp[nums[i] + nxt] = len;
            ans = max(ans,len);
        }
        return ans;
    }
};