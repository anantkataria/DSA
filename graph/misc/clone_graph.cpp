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
    
    Node* recur(Node* node, unordered_map<int, Node*>& newNodeStore){
        if(newNodeStore.find(node->val) == newNodeStore.end()){
            Node* newNode = new Node(node->val);
            newNodeStore[node->val] = newNode;
            for(auto n : node->neighbors){
                newNode->neighbors.push_back(recur(n, newNodeStore));
            }
            return newNode;
        }
        return newNodeStore[node->val];
    }
    
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<int, Node*> newNodeStore;
        return recur(node, newNodeStore);
    }
};