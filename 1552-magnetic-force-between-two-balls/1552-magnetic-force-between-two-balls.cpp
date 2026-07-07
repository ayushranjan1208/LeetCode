class Solution {
public:
    bool check(vector<int> &arr, int m, int mid){
        int n = arr.size();
        int c = 1, pos = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] - pos >= mid){
                c++;
                pos = arr[i];
            }
        }
        return c >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());

        int lo = 1, hi = position[n - 1] - position[0];
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(check(position,m,mid)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};