class Solution {
public:
    bool check(vector<int> &nums, int threshold, int mid){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (nums[i] + mid - 1) / mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int lo = 1, hi = *max_element(nums.begin(),nums.end());

        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(nums,threshold,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};