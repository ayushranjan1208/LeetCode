class NumArray {
public:
    int n;
    vector<int> segTree;

    void buildSegTree(int i, int l, int r, vector<int> &nums){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(2*i+1, l, mid, nums);
        buildSegTree(2*i+2, mid + 1, r, nums);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void update_seg(int id, int i, int l, int r, int val){
        if(l == r){
            segTree[i] = val;
            return;
        }

        int mid = (l + r) / 2;
        if(id <= mid){
            update_seg(id, 2*i+1, l, mid, val);
        }
        else{
            update_seg(id, 2*i+2, mid + 1, r, val);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];

    }

    int query(int st, int en, int i, int l, int r){
        if(l > en || r < st) return 0;

        if(st <= l && r <= en) return segTree[i];

        int mid = (l + r) / 2;
        return query(st, en, 2*i+1, l, mid) + query(st, en, 2*i+2, mid + 1, r);
    }

    NumArray(vector<int>& input_nums) {
        n = input_nums.size();
        segTree.assign(4*n, 0);

        buildSegTree(0, 0, n - 1, input_nums);
    }
    
    void update(int index, int val) {
        update_seg(index, 0, 0, n - 1, val);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */