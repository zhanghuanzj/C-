/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        if(!record.count(node->label)){
            UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
            record[node->label] = p;
            for(int i=0;i<node->neighbors.size();++i){
                p->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
            return p;
        }else{
            return record[node->label];
        }  
    }
private:
    map<int,UndirectedGraphNode*> record;
};