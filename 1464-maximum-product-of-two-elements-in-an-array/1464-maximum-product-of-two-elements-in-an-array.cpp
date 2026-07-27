class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = -1, maxi2 = -1;

        for(int i = 0; i < n; i++){
            if(maxi1 < nums[i]){
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else if(maxi2 < nums[i]) maxi2 = nums[i];
        }

        return (maxi1 - 1) * (maxi2 - 1);
    }
};