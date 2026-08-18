class Solution {
public:

    unordered_map<char,unordered_set<char>> adj;
    unordered_map<char, int> indegree;
    unordered_set<char> ch;

string topo() {

    queue<char> q;

    for (auto c : ch) {
        if (indegree[c] == 0) {
            q.push(c);
        }
    }

    string result = "";
    int count = 0;

    while (!q.empty()) {

        char curr = q.front();
        q.pop();

        result += curr;
        count++;

        for (auto next : adj[curr]) {

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (count != ch.size()) {
        return "";
    }

    return result;
}


       bool relation(string w1, string w2){

            int size1 = w1.size();
            int size2 = w2.size();
            int i =0;
            while(i<size1){
                ch.insert(w1[i]);
                i++;
            }
            i=0;
            while(i<size2){
                ch.insert(w2[i]);
                i++;
            }
                bool smaller = false;
            i=0;
            while(i<size1 && i<size2){
                
                    unordered_set<char> arr = adj[w2[i]];
                    char target = w1[i];

                    
                    if(!arr.contains(target)){
                        if(w1[i]!=w2[i]){
                            if(!adj[w1[i]].contains(w2[i])){
                            adj[w1[i]].insert(w2[i]);
                            indegree[w2[i]]++;
                            };
                            smaller = true;
                            break;
                            
                        }
                    }
                    else{
                        return false;
                    }
                    
                

                i++;
            }
    
            
                    if(size1>size2 && !smaller){
                        return false;
                    }
                    return true;
            


        }

    string foreignDictionary(vector<string>& words) {


        if(words.size()==1){
            string result;
            unordered_set<char> dup;
            for(auto& c: words[0]){
                if(!dup.contains(c)){
                result+=c;}
                dup.insert(c);
                
            }
            return result;
        }

        for(int i=0; i<words.size()-1;i++){
            int l=i;
            int r= i+1;

            bool result = relation(words[l], words[r]);

           if(!result){
            return "";
           }

        }

       string result = topo();
        return result;


    }
};
