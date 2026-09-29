#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=6;
    vector<vector<int>> graph(n+1);
    vector<int> indeg(n+1,0);
    auto add=[&](int u,int v){
        graph[u].push_back(v);
        indeg[v]++;
    };
    add(1,2);
    add(1,3);
    add(4,2);
    add(3,4);
    add(4,5);
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        topo.push_back(u);
        for(int v:graph[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    if(topo.size()==n){
        cout<<"Sort successfully:";
        for(int x:topo) cout<<x<<" ";
    }else{
        cout<<"Ring exists. Fail.";
    }
    return 0;
}