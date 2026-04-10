class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1 || s == ""){
            return false;
        }
        stack<char> st;
        unordered_map<char,char> m;
        m['{'] = '}';
        m['('] = ')';
        m['['] = ']';
        

        for(auto c : s){
           
                if(m[c]){
                    st.push(c);
                }
                else{
                    if(!st.empty() && m[st.top()]== c ){
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
        }
        if(st.size()!=0){
            return false;
        }
        return true;
    }
        
};

          

        

