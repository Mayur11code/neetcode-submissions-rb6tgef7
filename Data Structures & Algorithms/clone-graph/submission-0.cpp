/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void dfs(Node* copy,Node* node , unordered_set<Node*> &visited, unordered_map<int, Node*> &hash){

        if(node->neighbors.size()>0){
        for(auto& neighbor : node->neighbors){
            if(visited.contains(neighbor)){
                copy->neighbors.push_back(hash[neighbor->val]);
                continue;
            }
            Node* child = new Node(neighbor->val);
            copy->neighbors.push_back(child);
            visited.insert(neighbor);
            hash[neighbor->val]= child;
            dfs(child,neighbor, visited,hash);
        }
       
        }
    }


    Node* cloneGraph(Node* node) {
        
        if(node==nullptr){
            return nullptr;
        }
        Node* copy = new Node(node->val);
        unordered_set<Node*> visited;
        unordered_map<int, Node*> hash;
        hash[node->val]= copy;
        visited.insert(node);
        dfs(copy, node, visited, hash);
        return copy;
    }
};
