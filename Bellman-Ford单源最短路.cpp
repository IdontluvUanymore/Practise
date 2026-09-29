#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int u;
	int v;
	int weight;
};
int main(){
	vector<edge> graph;
    auto add=[&](int u,int v,int d){
        graph.push_back({u,v,d});
    };
    add(1,2,3);
    add(1,3,4);
    add(3,2,-2);
    vector<int> dist(4,1e9);
    dist[1]=0;
    for(int i=1;i<=2;i++){
    	for(auto [U,V,W]:graph){
    		if(dist[U]+W<dist[V]){
    			dist[V]=dist[U]+W;
			}
		}
	}
    for(auto [U,V,W]:graph){
    	if(dist[U]+W<dist[V]){
    		cout<<"Negetive ring exists.";
		}
	}
	cout<<"the shortest distance from 1 to 2 is: "<<dist[2];
	return 0;
}
