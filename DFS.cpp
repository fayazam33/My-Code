#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
const int N=1e6+7;
#define Fayaz() ios_base::sync_with_stdio(false) ;cin.tie(0);cout.tie(0);
const int INF= 1e9;
int visited[N];
vector<int>adj_list[N];

int dfs(int node){
	cout<<node<<endl;
	visited[node]=1;
	//for(int adj_node : adj_list[node])
	// for(int i=0;i<adj_list[node].size();i++){
            // int adj_node=adj_list[node][i];
		// if(visited[adj_node]==0){
			// //visited[adj_node]=1;
			// dfs(adj_node);
		// }
// 
	// }
	for(int adj_node:adj_list[node]){
		if(visited[adj_node]==0){
			dfs(adj_node);
		}
		
		
	}


}


int main(){
	int node,edge;cin>>node>>edge;

	for(int i=0;i<edge;i++){
		int u,v;
		cin>>u>>v;

		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	int source ;
	cin>>source;
	dfs(source);
	return 0;



}
