#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 2e5+1;
int n,m;
vector<array<ll,2>> adj[mxn];
vector<ll> dist(mxn, LLONG_MAX);

void dijkstras(int s){
	dist[s] = 0;	
	priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
	pq.push({0, s});
	while(!pq.empty()){
		array<ll,2> cur = pq.top();
		pq.pop();
		if(cur[0]>dist[cur[1]]) continue;
		for(array<ll,2> child : adj[cur[1]]){
			if(dist[cur[1]]+child[1]<dist[child[0]]){
				dist[child[0]] = dist[cur[1]]+child[1];
				pq.push({dist[child[0]], child[0]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int s,d,w;
		cin>>s>>d>>w;
		adj[s].push_back({d, w});
	}
	dijkstras(1);
}
