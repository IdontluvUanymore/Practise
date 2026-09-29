#include<iostream>
using namespace std;
#define INF (1000000000)
int main(){
	int graph[5][5]={
		{0,-1,INF,3,INF},
		{2,0,1,INF,2},
		{INF,1,0,INF,4},
		{INF,INF,1,0,INF},
		{2,INF,5,-2,0}
	};
	int dist[5][5];
	int path[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dist[i][j]=graph[i][j];
			path[i][j]=(graph[i][j]==INF?-1:i);
		}
	}
	for(int mid=0;mid<5;mid++){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(dist[i][mid]+dist[mid][j]<dist[i][j]){
					dist[i][j]=dist[i][mid]+dist[mid][j];
					
				}
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<"从 "<<i<<" 到 "<<j<<" 的最短距离为 "<<dist[i][j]<<endl;
		}
	}
	return 0;
}
