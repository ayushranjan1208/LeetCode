class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n - 2; i++){
            int tar = -nums[i];
            int s = i + 1, e = n - 1;
            while(s < e){
                int sum = nums[s] + nums[e];
                if(sum == tar){
                    ans.push_back({-tar,nums[s],nums[e]});
                    while(s < e && nums[s] == nums[s+1]) s++;
                    while(e > s && nums[e] == nums[e-1]) e--;
                    s++;
                    e--;
                    continue;
                }
                else if(sum > tar) e--;
                else s++;
            }
            while(i < n - 1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};