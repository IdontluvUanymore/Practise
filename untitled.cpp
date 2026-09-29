#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
};
vector<edge> graph;
vector<int> parent;
int find_and_simplify(int x){
    if(parent[x]==x) return x;
    return parent[x]=find_and_simplify(parent[x]);
}
void unite(int a,int b){
    int pa=find_and_simplify(a);
    int pb=find_and_simplify(b);
    if(pa>pb){
        parent[b]=pa;
    }else{
        parent[a]=pb;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int U,V;
        cin>>U>>V;
        graph.push_back({U,V});
    }
    parent.resize(n+1);
    for(int i=0; i<=n; i++){
        parent[i]=i;
    }
    for(auto e:graph){
        unite(e.u,e.v);
    }
    for(int i=1;i<=n;i++){
        cout<<parent[i]<<endl;
    }
    return 0;
}