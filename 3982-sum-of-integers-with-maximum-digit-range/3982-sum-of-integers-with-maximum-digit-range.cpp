class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();

        int sum = 0, range = 0;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);

            int mini = 10, maxi = 0;
            for(auto e : s){
                mini = min(mini, e - '0');
                maxi = max(maxi, e - '0');
            }
            int dif = maxi - mini;
            if(dif > range){
                sum = nums[i];
                range = dif;
            }
            else if(dif == range) sum += nums[i];
        }
        return sum;
    }
};