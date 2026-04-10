#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // 1. LEFT PASS: 
        // Calculate the prefix product and store it in the result array.
        // res[i] will contain the product of all elements to the left of i.
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            res[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // 2. RIGHT PASS:
        // Calculate the suffix product on the fly and multiply it with res[i].
        // rightProduct will keep track of the product of all elements to the right of i.
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return res;
    }
};