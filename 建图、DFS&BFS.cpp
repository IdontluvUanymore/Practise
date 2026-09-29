#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class graph{
	private:
		int max;
		int n;
		vector<vector<int> > edge;
	public:
		graph(){
			n=0;
			max=0;
		}
		void push_back(int u,int v){
			n+=1;
			int temp=u>v?u:v;
			max=temp>max?temp:max;
			edge.resize(max+1);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int size(){
			return n;
		}
		bool empty(){
			return n==0;
		} 
		void print(){
			for(int i=1;i<edge.size();i++){
				for(int j=0;j<edge[i].size();j++){
					cout<<i<<" --> "<<edge[i][j]<<endl;
				}
			}
		}
		void DFS(int start){
			vector<bool> vis(max+1,false);
			dfs(start,vis);
			cout<<"\n";
		}
		void dfs(int u,vector<bool>& visited){
			visited[u]=true;
			cout<<u<<" ";
			for(int i=0;i<edge[u].size();i++){
				if(!visited[edge[u][i]]){
					dfs(edge[u][i],visited);
				}
			} 
		}
		void BFS(int start,int target){
			vector<bool> visited(max+1,false);
			vector<int> dist(max+1,-1);
			queue<int> q;
			visited[start]=true;
			dist[start]=0;
			q.push(start);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=0;i<edge[u].size();i++){
					int v=edge[u][i];
					if(!visited[v]){
						visited[v]=true;
						dist[v]=dist[u]+1;
						q.push(v);
					}
				}
			}
			cout<<"从 "<<start<<" 到 "<<target<<" 的最短距离是 "<<dist[target]<<endl;
		} 
};
int main(){
	graph g;
	g.push_back(1,2);
	g.push_back(2,3);
	g.push_back(3,4);
	g.push_back(2,4);
	g.push_back(2,5);
	g.print();
	g.DFS(2);
	g.BFS(1,5);
    return 0;
}
