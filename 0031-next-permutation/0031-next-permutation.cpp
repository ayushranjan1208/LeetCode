class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        bool flag = 0;
        for(int i = n - 2; i >= 0; i--){
            pivot = i;
            if(nums[i] < nums[i+1]){
                flag = true;
                break;
            }
        }
        if(flag == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = n - 1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        reverse(nums.begin()+pivot+1,nums.end());
    }
};