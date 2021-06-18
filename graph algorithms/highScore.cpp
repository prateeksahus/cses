//bellman ford for max distance
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct edge{
	ll a, b, c;
};
const int mxn = 2.5e3;
int n,m;
vector<edge> edges(mxn);
vector<int> adj[mxn], adj1[mxn];
vector<ll> dist(mxn, 1e18);
vector<bool> vis(mxn), vis1(mxn);
bool flag = 0;

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u])
		if(!vis[v])
			dfs(v);
}

void dfs1(int u){
	vis1[u] = 1;
	for(int v : adj1[u])
		if(!vis1[v])
			dfs1(v);
}

void bellman_ford(int u){
	dist[u] = 0;
	for(int i=0;i<n;i++){
		for(edge e : edges){
			if(vis[e.a]&&vis1[e.b]&&dist[e.a]+e.c<dist[e.b]){
				if(i==n-1) flag = 1;
				dist[e.b] = dist[e.a]+e.c;
			}
		}
	}
	if(flag) cout<<-1;
	else{
		cout<<-dist[n-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		--a, --b;
		adj[a].push_back(b);
		adj1[b].push_back(a);
		edges.push_back({a, b, -c});
	}
	dfs(0);
	dfs1(n-1);
	bellman_ford(0);
}
