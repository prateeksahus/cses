// bipartite test
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj(1e5+1);
vector<bool> vis(1e5+1);
vector<int> col(1e5+1);
int n, m; 

bool dfs(int x, int c){
	vis[x] = 1;
	col[x] = c;
	for(int n : adj[x]){
		if(!vis[n]){
			if(dfs(n,c^1)==false)
				return false;
		}
		else if(col[x]==col[n])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int s, d;
		cin>>s>>d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(!dfs(i,1)){
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<col[i]+1<<" ";
	}
}

