class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if(n > m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int len = n + m;
        int lo = 0, hi = n;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            int num1 = mid;
            int num2 = (n + m + 1) / 2 - num1;

            int pre1 = (num1 == 0) ? INT_MIN : nums1[num1 - 1];
            int nxt1 = (num1 == n) ? INT_MAX : nums1[num1];
            int pre2 = (num2 == 0) ? INT_MIN : nums2[num2 - 1];
            int nxt2 = (num2 == m) ? INT_MAX : nums2[num2];

            int e1 = max(pre1,pre2), e2 = min(nxt1,nxt2);

            if(pre1 <= nxt2  && pre2 <= nxt1){
                if(len % 2){
                    return double(e1);
                }
                else{
                    return (e1 + e2) / 2.0;
                }
            }
            if(pre1 > nxt2){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return -1;
    }
};