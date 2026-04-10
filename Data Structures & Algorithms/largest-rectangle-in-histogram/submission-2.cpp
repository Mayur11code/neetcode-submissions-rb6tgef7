class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        for(int i = 0; i<heights.size(); i++){
            if( st.empty() || heights[i]>=heights[st.top()] ){
                st.push(i);
            }
            else if ( heights[i] < heights[st.top()] ){
                int right = i;
                int left;
                while(!st.empty() && heights[st.top()] > heights[i] ){
                    int curr = heights[st.top()];
                    st.pop();
                    left = st.empty() ? -1 : st.top();
                    int curr_area = curr * (right - left -1);
                    if(curr_area > max_area){
                        max_area = curr_area;
                    }

                }
                st.push(i);
            }
            
        }

        if(!st.empty()){
                int right = heights.size();
                int left;
                while(!st.empty()){
                    int curr = heights[st.top()];
                    st.pop();
                    left = st.empty() ? -1 : st.top();
                    int curr_area = curr * (right - left -1);
                    if(curr_area > max_area){
                        max_area = curr_area;
                    }
                }
            }
        return max_area;
        
    }
};
