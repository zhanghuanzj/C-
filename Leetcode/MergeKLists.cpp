class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return merge(lists,0,lists.size()-1);
    }
    ListNode *merge(vector<ListNode *> &list,int left,int right){
        if(left>right) return nullptr;
        if(left==right) return list[left];
        int mid = (left+right)/2;
        ListNode *p = merge(list,left,mid);
        ListNode *q = merge(list,mid+1,right);
        ListNode node(0);
        ListNode *cur = &node;
        while(q&&p){
            if(p->val < q->val){
                cur->next = p;
                p = p->next;
            }else{
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        if(p) cur->next = p;
        if(q) cur->next = q;
        return node.next;
    }
};