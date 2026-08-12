struct Node {
    Node* bits[2];

    bool isSet(int b){
        return bits[b] != NULL;
    }

    void set(int b, Node* node){
        bits[b] = node;
    }

    Node* get(int b){
        return bits[b];
    }
};

class Solution {
private: Node* root;
public:
    Solution(){
        root = new Node();
    }
    void insert(int n){
        Node* node = root;
        for(int i = 30; i >= 0; i--){
            bool bit = (1 << i) & n;
            if(!node->isSet(bit)){
                node->set(bit, new Node());
            }

            node = node->get(bit);
        }
    }
    int XOR(int n){
        Node* node = root;
        int num = 0;
        for(int i = 30; i >= 0; i--){
            bool bit = (1 << i) & n;
            if(bit == 1){
                if(node->isSet(0)){
                    node = node->get(0);
                }
                else{
                    node = node->get(1);
                    num += (1 << i);
                }
            }
            else{
                if(node->isSet(1)){
                    node = node->get(1);
                    num += (1 << i);
                }
                else{
                    node = node->get(0);
                }
            }
        }
        return num;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(auto &n : nums) insert(n);

        int ans = 0;
        for(auto &n : nums){
            int num = XOR(n);
            ans = max(ans,n ^ num);
        }

        return ans;
    }
};