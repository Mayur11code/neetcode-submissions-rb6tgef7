class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i = 0 ; i < speed.size();i++){
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end(),greater<pair<int, int>>());

        stack<pair<int,int>> st;
        for(auto &car : v){
            if(st.empty()){
                st.push(car);
            }
            else if((1.0*(target-(st.top().first))/st.top().second)<((1.0*(target-(car.first))/car.second))){
                st.push(car);
            }
        }

        return st.size();

    }
};
