class Solution {
public:
    bool check(vector<int> &weights, int days, int mid){
        int n = weights.size();

        int tot = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            if(sum > mid){
                sum = weights[i];
                tot++;
            }
        }
        return tot <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(),weights.end()), 
        hi = accumulate(weights.begin(),weights.end(),0);

        int ans = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(check(weights,days,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};