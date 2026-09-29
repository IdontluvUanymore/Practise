#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u;
    int v;
    int w;
};
vector<int> parent;
int find_and_simplify(int x){
    if(parent[x]==x) return x;
    parent[x]=find_and_simplify(parent[x]);
    return parent[x];
}
void unite(int a,int b){
    int pa=find_and_simplify(a);
    int pb=find_and_simplify(b);
    if(pa!=pb) parent[a]=pb;
}
int main(){
    vector<edge> graph={
        {1,2,1},
        {2,3,3},
        {3,4,2},
        {1,4,4},
        {2,4,5}
    };
    sort(graph.begin(),graph.end(),[](edge a,edge b){
        return a.w<b.w;
    });
    parent.resize(5);
    for(int i=0;i<5;i++){
        parent[i]=i;
    }
    int mst_weight=0;
    int cnt=0;
    for(auto &e:graph){
        if(find_and_simplify(e.u)!=find_and_simplify(e.v)){
            unite(e.u,e.v);
            mst_weight+=e.w;
            cnt++;
            cout<<"choose:"<<e.u<<"->"<<e.v<<"(weight:"<<e.w<<")"<<endl;
        }
        if(cnt==3) break;
    }
    cout<<"mst_weight:"<<mst_weight<<endl;
    return 0;
}