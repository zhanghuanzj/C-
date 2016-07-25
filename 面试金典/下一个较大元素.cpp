class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;--i){
            int top = s.top();
            while(top!=-1 && top<A[i]){
                s.pop();
                top = s.top();
            }
            s.push(A[i]);
            A[i] = top;
        }
        return A;
    }
};