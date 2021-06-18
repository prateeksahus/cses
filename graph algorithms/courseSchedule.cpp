//topological sort
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 1e5, mxm = 2e5;
int n,m;
vector<int> adj[mxm], state(mxn, 0), ans;
vector<bool> vis(mxn);

void dfs(int u){
	vis[u] = 1;
	state[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
		else if(state[v]!=2){
			cout<<"IMPOSSIBLE";
			exit(0);
		}
	}
	state[u] = 2;
	ans.push_back(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		--a, --b;
		adj[a].push_back(b);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
	for(int x: ans){
		cout<<x+1<<" ";
	}
}
