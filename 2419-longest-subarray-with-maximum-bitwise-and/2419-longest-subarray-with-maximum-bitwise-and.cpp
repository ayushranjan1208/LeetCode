class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        int max_len = 0, len = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != maxi) len = 0;

            if(nums[i] == maxi) len++;

            max_len = max(max_len,len);
        }
        return max_len;
    }
};