class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i =0,j= heights.size()-1;
        int max = 0;

        while(i<j){
            int amount = min(heights[i], heights[j])*(j-i);
            if( amount > max ){
                max = amount;
            }
            if(heights[i]> heights[j]){
                j--;
            } 
            else i++;

        }

        return max;
        
    }
};
