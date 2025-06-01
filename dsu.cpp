/*
	Problem Link - Applying kruskal minimum spanning tree with DSU
	Author - Fayaz Ali Muktadir

	*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define Fayaz() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 1e5+10;
int parent[N];
int size[N];
void make(int v){
	parent[v]=v;
	size[v]=1;
}

int find(int v){
	if(parent[v]==v)return v;
	return parent[v] = find(parent[v]);
	
}

void Union(int a , int b){
	 a = find(a);
	 b = find(b);
	 if(a!=b){
	 	if(size[a]<size[b])swap(a,b);
	 	parent[b]=a;
	 	size[a]+=size[b];
	 }
}

int main(){
	int n, m;
	cin>>n>>m;
	vector<pair<int , pair<int , int >>>edges;
	for(int i =0 ; i<m ; i++){
		int wt , u , v;
		cin>>u >>v>>wt;
		edges.push_back({wt,{u,v}});
	}
	sort(edges.begin(), edges.end());
	int total_cost=0;
	for(int i =1 ;i<=n ; i++)make(i);
	for(auto &edge :edges){
		int wt=edge.first;
		int u= edge.second.first;
		int v= edge.second.second;
		if(find(u)==find(v))continue;
		Union(u,v);
		total_cost+=wt;
		cout<<u<<" "<<v<<" "<<wt<<endl;
			}
		cout<<total_cost<<endl;
			
	
	
}
/*input
6 9 
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7


output
1 4 1
1 2 2
3 2 3
5 1 4
2 6 7
17
*/

