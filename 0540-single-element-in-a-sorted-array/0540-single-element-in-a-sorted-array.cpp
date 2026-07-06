class Solution {
public:
    bool check(vector<int> &nums, int n, int mid){
        int id1, id2;
        if(mid > 0 && nums[mid-1] == nums[mid]){
            id1 = mid - 1,id2 = mid;
        }
        else{
            id1 = mid, id2 = mid + 1;
        }

        if(id1 % 2 == 0) return true;
        return false;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int lo = 0, hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            bool t = true;
            if(mid > 0){
                if(nums[mid - 1] == nums[mid]) t = false;
            }
            if(mid < n - 1){
                if(nums[mid + 1] == nums[mid]) t = false;
            }

            if(t) return nums[mid];

            if(check(nums,n,mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1; 
    }
};