class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 1, hi = 2001;

        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            int num = lower_bound(arr.begin(),arr.end(),mid) - arr.begin();
            int need = mid - num;

            if(need == k && (num == arr.size() || mid != arr[num])) return mid;

            if(need > k){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};