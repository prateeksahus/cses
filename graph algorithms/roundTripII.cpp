//cycle detection and printing in directed graph using concept of toplogical sorting
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 1e5, mxm = 2e5;
int n, m;
vector<int> adj[mxn], ans, state(mxn, 0);
vector<bool> vis(mxn);
unordered_map<int, int> par;

void dfs(int u){
	vis[u] = 1;
	state[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			par[v] = u;
			dfs(v);
		}
		else if(state[v]!=2){
			fill(vis.begin(), vis.end(), 0);
			int node = u;
			vis[v] = 1;
			ans.push_back(v);
			while(!vis[node]){
				ans.push_back(node);
				node = par[node];
			}
			ans.push_back(v);
			reverse(ans.begin(), ans.end());
			cout<<ans.size()<<endl;
			for_each(ans.begin(), ans.end(), [](int x){
								cout<<x+1<<" ";
							});
			exit(0);
		}
	}
	state[u] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;++i){
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
	cout<<"IMPOSSIBLE";
}
