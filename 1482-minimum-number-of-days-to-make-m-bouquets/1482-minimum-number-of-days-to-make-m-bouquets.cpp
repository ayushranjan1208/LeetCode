class Solution {
public:
    bool check(vector<int> &bloomDay, int m, int k, int mid){
        int n = bloomDay.size();
        int tot = 0;

        int c = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                c++;
            }
            else{
                tot += c/k;
                c = 0;
            }
        }
        tot += c/k;

        return tot >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int lo = 1, hi = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(bloomDay,m,k,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};