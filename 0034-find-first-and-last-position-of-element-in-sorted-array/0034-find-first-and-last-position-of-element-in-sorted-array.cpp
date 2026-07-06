class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int lo = 0, hi = n - 1;
        int first_pos = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target){
                first_pos = mid;
                hi = mid - 1;
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }

        lo = 0, hi = n - 1;
        int last_pos = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] == target){
                last_pos = mid;
                lo = mid + 1;
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }

        return {first_pos,last_pos};
    }
};