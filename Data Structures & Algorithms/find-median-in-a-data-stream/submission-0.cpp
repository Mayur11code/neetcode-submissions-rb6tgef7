class MedianFinder {
public:


      struct Compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
      struct Comparemax {
        bool operator()(int a, int b) {
            return a < b;
        }
    };
    
    priority_queue<int, vector<int>, Compare> pqmin;
    priority_queue<int, vector<int>, Comparemax> pqmax;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqmin.empty() || num <= pqmin.top()){
            pqmax.push(num);
        }
        else{
            pqmin.push(num);
        }

        if(pqmax.size()>pqmin.size()+1){
            int a = pqmax.top();
            pqmin.push(a);
            pqmax.pop();
        }
        if(pqmax.size()+1<pqmin.size()){
            int a = pqmin.top();
            pqmax.push(a);
            pqmin.pop();
        }

    }
    
    double findMedian() {

        if((pqmax.size()+pqmin.size())%2 == 0){
            return ((pqmin.top() + pqmax.top())/2.0);

        }
        else if ( pqmax.size()> pqmin.size()){
            return pqmax.top();
        }
        else {return pqmin.top();}
    }
};
