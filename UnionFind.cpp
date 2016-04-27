// 初始化并查集
#define N 100
int father[N];
void init() {
    for(int i=0; i<N; i++)
      father[i] = i;
}
// 合并两个元素所在的集合
void union(int x,int y) {
    x = getfather(x);
    y = getfather(y);
    if(x!= y)
       father[x]=y;
}
// 判断两个元素是否属于同一个集合
bool same(int x,int y) {
    return getfather(x)==getfather(y);
}
// 获取根结点
int getfather(int x) {
    while(x != father[x])
      x = father[x];
    return x;
}