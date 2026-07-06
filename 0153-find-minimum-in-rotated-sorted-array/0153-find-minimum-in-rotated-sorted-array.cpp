class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        int ans = INT_MAX;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] < nums[0]){
                ans = nums[mid];
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        ans = min(ans,nums[0]);

        return ans;
    }
};