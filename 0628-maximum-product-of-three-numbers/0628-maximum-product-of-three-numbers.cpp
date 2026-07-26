class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        int pos1 = -1000, pos2 = -1000, pos3 = -1000;
        int neg1 = 0, neg2 = 0;

        for(int i = 0; i < n; i++){
            if(pos1 < nums[i]){
                pos3 = pos2, pos2 = pos1, pos1 = nums[i];
            }
            else if(pos2 < nums[i]){
                pos3 = pos2, pos2 = nums[i];
            }
            else if(pos3 < nums[i]) pos3 = nums[i];

            if(neg1 > nums[i]){
                neg2 = neg1, neg1 = nums[i];
            }
            else if(neg2 > nums[i]){
                neg2 = nums[i];
            }
        }

        return max(pos1 * pos2 * pos3, neg1 * neg2 * pos1); 

    }
};