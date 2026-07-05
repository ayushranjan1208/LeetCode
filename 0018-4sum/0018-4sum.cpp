class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                long long new_tar = 1ll*target - 1ll*nums[i] - 1ll*nums[j];
                int s = j + 1, e = n - 1;

                while(s < e){
                    long long sum = nums[s] + nums[e];
                    if(sum == new_tar){
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        while(s < e && nums[s] == nums[s+1]) s++;
                        while(e > s && nums[e] == nums[e-1]) e--;
                        s++;
                        e--;
                    }
                    else if(sum > new_tar) e--;
                    else s++;
                }
            }
        }
        return ans;
    }
};