class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 1, num = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == num) c++;
            else c--;
            if(c == 0){
                c = 1;
                num = nums[i];
            }
        }
        return num;
    }
};