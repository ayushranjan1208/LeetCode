class Solution {
public:
    bool isPeak(int i, vector<int>& nums) {
        if (i <= 0 || i >= nums.size() - 1) return false;
        return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        // SQRT DECOMPOSITION TRY KRTE HAI BAN JANA CHAHIYE :)

        int n = nums.size();
        int len = sqrt(n) + 1;
        vector<int> block(len + 1,0);

        for(int i = 1; i < n - 1; i++){
            if(isPeak(i, nums)){
                block[i/len]++;
            }
        }

        vector<int> ans;
        for(auto q : queries){
            if(q[0] == 1){
                int l = q[1], r = q[2];
                if(r - l < 2){
                    ans.push_back(0);
                    continue;
                }
                int peak = 0;
                for(int i = l; i <= r; ){
                    if(i % len == 0 && i+len-1 <= r){
                        peak += block[i/len];
                        i += len;
                    }
                    else{
                        if(isPeak(i, nums)) peak++;
                        i++;
                    }
                }
                if(isPeak(l, nums)) peak--;
                if(isPeak(r, nums)) peak--;

                ans.push_back(peak);
            }
            else{
                int ind = q[1], val = q[2];
                
                for(int i = max(1, ind - 1); i <= min(n - 2, ind + 1); i++) {
                    if(isPeak(i, nums)) block[i/len]--;
                }

                nums[ind] = val;

                for(int i = max(1, ind - 1); i <= min(n - 2, ind + 1); i++) {
                    if(isPeak(i, nums)) block[i/len]++;
                }
            }
        }

        return ans;
    }
};