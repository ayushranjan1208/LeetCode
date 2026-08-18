class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = -1;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            maxi = max(maxi,nums[i]);
        }
        
        if(k == 1){
            int ans = -1;
            for(auto it : mp){
                if(it.second == 1) ans = max(ans,it.first);
            }
            return ans;
        }

        if(k == n) return maxi;

        int a = -1, b = -1;
        if(mp[nums[0]] == 1) a = nums[0];
        if(mp[nums[n - 1]] == 1) b = nums[n - 1];

        return max(a,b);


    }
};