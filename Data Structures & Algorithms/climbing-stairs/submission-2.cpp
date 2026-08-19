    class Solution {
    public:
        int climbStairs(int n) {
            int wn1= 1;
            int wn2 = 1;
            int wnt =0;

            for(int i=1; i<n; i++){
                wnt = wn1 + wn2;
                wn2= wn1;
                wn1 = wnt;
            }

            return wnt == 0 ? n : wnt;
        }
    };
