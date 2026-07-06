class Solution {
public:
    bool check(vector<int> &piles,int h,int mid){
        int n = piles.size();
        long long time = 0;

        for(int i = 0; i < n; i++){
            time += (1ll*piles[i] + mid - 1) / mid;
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int lo = 1, hi = *max_element(piles.begin(),piles.end());
        int ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(piles,h,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};