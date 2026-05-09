/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        if(root == nullptr){
            return "";
        }
        string serial;
        q.push(root);
        while(q.size()!=0){
            TreeNode* front = q.front();
            if(front == nullptr){
                serial += "null,";
                q.pop();
                continue;
            }
            serial+= to_string( front->val) + ",";
            q.push(front->left);
            q.push(front->right);
            q.pop();
        }

        return serial;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 2. Load it into a stringstream
        stringstream ss(data);

        // 3. Create a temporary string to hold each piece
        string val;
        queue<TreeNode* > q;
        getline(ss,val,',');
        if(val == ""){
            return nullptr;
        }
        TreeNode* first = new TreeNode(std::stoi(val));
        q.push(first);


        // 4. Use getline() to read up to the next comma
        while (!q.empty()) {

           
            TreeNode* leftnode;
            TreeNode* rightnode;
            getline(ss, val, ',');
            if(val != "null"){
                 int l = std::stoi(val);
               leftnode = new TreeNode(l);
            }
            else{
                leftnode = nullptr;
            }

            getline(ss,val,',');
            
            if(val != "null"){
                 int r = std::stoi(val);
               rightnode = new TreeNode(r);
            }
            else{
                rightnode = nullptr;
            }
            if(leftnode!= nullptr){
            q.push(leftnode);}
            if(rightnode!=nullptr){
            q.push(rightnode);}

            if(q.front() == nullptr){
                while(q.front()!= nullptr){
                    q.pop();
                }
                continue;
            }
           
            TreeNode* root = q.front();
            root->left = leftnode;
            root->right = rightnode;
            q.pop();
  
        }

        return first;
    }
};
