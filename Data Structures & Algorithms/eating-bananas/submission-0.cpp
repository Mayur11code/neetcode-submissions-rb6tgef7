class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k ;
        int max_bananas=0;
        for(auto &n : piles){
            if(n>max_bananas){
                max_bananas = n;
            }
        }

        int left=1,right =max_bananas;
        while(left<=right){

           int mid = left + (right-left)/2;
           int hours=0;
            for(auto &p : piles){
                hours+= (p+mid-1)/mid;
            }
            if(hours<=h){
                k= mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }



        }

        return k;

        
    }
};
