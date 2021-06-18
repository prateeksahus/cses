//dijkstras for k shortest distance
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 1e5, mxm = 2e5;
int n, m, k;
vector<array<ll,2>> adj[mxm];
vector<vector<ll>> dist(mxn, vector<ll>(10, 1e18));

void dijkstras(int s){
	priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
	pq.push({0, s});
	while(pq.size()){
		ll d = pq.top()[0];
		ll u = pq.top()[1];
		pq.pop();
		if(dist[u][k-1]<d) continue;
		for(array<ll,2> v : adj[u]){
			if(d+v[1]<dist[v[0]][k-1]){
				dist[v[0]][k-1] = d+v[1]; 
				pq.push({dist[v[0]][k-1], v[0]});
				sort(dist[v[0]].begin(), dist[v[0]].end());
			}
		}
	}
	for(int i=0;i<k;i++){
		cout<<dist[n-1][i]<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		ll a, b, c;
		cin>>a>>b>>c;
		--a, --b;
		adj[a].push_back({b, c});
	}
	dijkstras(0);
}
