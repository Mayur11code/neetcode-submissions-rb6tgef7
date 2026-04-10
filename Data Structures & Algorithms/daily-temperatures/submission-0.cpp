class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size());
        for(int i=0; i<temperatures.size();i++){
            if(st.empty()){
                st.push(i);
            }
            else if(temperatures[st.top()]> temperatures[i]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                    int j = st.top();
                    result[j] = i-j;
                    st.pop();
                }
                st.push(i);
            }
        }
        if(!st.empty()){
            while(!st.empty()){
                int j = st.top();
                result[j]=0;
                st.pop();
            }
        }
        return result;
    }
};
