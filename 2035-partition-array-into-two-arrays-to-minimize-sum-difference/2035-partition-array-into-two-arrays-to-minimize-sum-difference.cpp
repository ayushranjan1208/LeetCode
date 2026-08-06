class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int,vector<int>> mp1,mp2;

        for(int i = 0; i < (1 << n); i++){
            int cnt = 0, sum = 0;

            for(int k = 0; k < n; k++){
                if((1 << k) & i){
                    sum += nums[k];
                    cnt++;
                }
            }
            mp1[cnt].push_back(sum);
        }

        for(int i = 0; i < (1 << n); i++){
            int cnt = 0, sum = 0;

            for(int k = 0; k < n; k++){
                if((1 << k) & i){
                    sum += nums[k + n];
                    cnt++;
                }
            }
            mp2[cnt].push_back(sum);
        }

        for(auto &[c,v] : mp2) sort(v.begin(),v.end());

        int ans = INT_MAX;
        int sum = accumulate(nums.begin(),nums.end(),0);

        for(auto &[lCnt,v] : mp1){

            int rCnt = n - lCnt;
            vector<int> &rPart = mp2[rCnt];
            for(auto e : v){
                int to_find = (sum - 2 * e) / 2;
                int lo = lower_bound(rPart.begin(),rPart.end(),to_find) - rPart.begin();
                int temp;
                if(lo < rPart.size()){
                    temp = abs(2*(rPart[lo] + e) - sum);
                    ans = min(ans,temp);
                }
                lo--;
                if(lo >= 0 && lo < rPart.size()){
                    temp = abs(2*(rPart[lo] + e) - sum);
                    ans = min(ans,temp);
                }
            }
        }

        return ans;
    }
};