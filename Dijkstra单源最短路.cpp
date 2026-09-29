#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<vector<pair<int,int> > > edge(7);
    auto add=[&](int u,int v,int d){
        edge[u].push_back({v,d});
        edge[v].push_back({u,d});
    };
    add(1,2,1);
    add(1,6,2);
    add(2,3,1);
    add(2,5,2);
    add(3,4,1);
    add(4,5,1);
    add(4,6,2);
    int start,target;
    cin>>start>>target;
    vector<int> dist(8,1e9);
    vector<bool> done(8,false);
	priority_queue<pair<int,int> > pq;
	dist[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		int d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(done[u]){
			continue;
		}else{
			done[u]=true;
		}
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].first;
			int w=edge[u][i].second;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				pq.push({-dist[v],v});
			}
		}
	}
	cout<<"从 "<<start<<" 到 "<<target<<" 的最短路径距离为 "<<dist[target]<<endl;
    return 0;
}
