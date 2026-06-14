class Solution {
public:
        struct Compare{
       bool operator()(int a, int b){
            return a<b;
        }
    };

    

    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int, vector<int>, Compare> pq;

        for(auto& p : stones){
            pq.push(p);
        }

        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();



            if(x>=y){
                pq.push(x-y);
            }
            else{
                pq.push(y-x);
            }

        }

        return pq.top();



    }
};
