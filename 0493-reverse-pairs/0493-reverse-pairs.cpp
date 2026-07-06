class Solution {
public:
    int countpairs(vector<int> &nums, int l, int r){
        if(l >= r) return 0;

        int m = l + (r - l)/2;

        int cnt = 0;

        cnt += countpairs(nums,l,m);

        cnt += countpairs(nums,m + 1,r);

        cnt += merge(nums,l,m,r);

        return cnt;
    }
    int merge(vector<int> &nums, int l, int m, int r){

        int n1 = m - l + 1, n2 = r - m;
        vector<int> temp1,temp2;

        for(int i = l; i <= m; i++) temp1.push_back(nums[i]);
        for(int i = m + 1; i <= r; i++) temp2.push_back(nums[i]);

        int c = 0;
        int q = 0;
        for(int p = 0; p < n1; p++){
            while(q < n2 && temp1[p] > 1ll*2*temp2[q]) q++;
            c += q;
        }

        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2){
            if(temp1[i] < temp2[j]) nums[k++] = temp1[i++];
            else{
                nums[k++] = temp2[j++];
            }
        }
        while(i < n1) nums[k++] = temp1[i++];

        while(j < n2) nums[k++] = temp2[j++];

        return c;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return countpairs(nums,0,n - 1);
    }
};