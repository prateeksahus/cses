//dijkstras algo
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 2e5;
int n,m;
vector<array<ll,2>> adj[mxn], adj2[mxn];
vector<ll> dist(mxn, 1e18), dist2(mxn, 1e18);

void dijkstra(int u, vector<array<ll,2>> adj[mxn], vector<ll>& dist){
	dist[u] = 0;
	priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
	pq.push({0, u});
	while(pq.size()){
		array<ll,2> node = pq.top();
		pq.pop();
		if(dist[node[1]]<node[0]) continue;
		for(array<ll,2> v : adj[node[1]]){
			if(dist[node[1]]+v[1]<dist[v[0]]){
				dist[v[0]] = dist[node[1]]+v[1];
				pq.push({dist[v[0]], v[0]});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		--a, --b;
		adj[a].push_back({b, c});
		adj2[b].push_back({a, c});
	}
	dijkstra(0, adj, dist);
	dijkstra(n-1, adj2, dist2);
	ll ans = 1e18;
	for(int i=0;i<n;i++){
		for(array<ll,2> v : adj[i]){
			ans = min(ans, dist[i]+(v[1]/2)+dist2[v[0]]);
		}
	}
	cout<<ans;
}
