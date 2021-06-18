//dfs + cycle detection + backtracking
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

vector<vector<int>> adj(1e5+1);
vector<bool> vis(1e5+1);
map<int,int> par;
vector<int> ans;
int n,m;

bool dfs(int n, int p){
	vis[n] = 1;
	par[n] = p;
	for(int c : adj[n]){
		if(!vis[c]){
			if(dfs(c, n)==true)
				return true;
		}
		else if(c!=p){
			fill(vis.begin(), vis.end(), 0);
			int node = n;
			vis[c] = 1;
			ans.push_back(c);
			while(!vis[node]){
				vis[node] = 1;
				ans.push_back(node);
				node = par[node];
			}
			ans.push_back(c);
			return true;
		}
	}
	return false;
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
			if(dfs(i, 0)){
				break;
			}
		}
	}
	if(ans.size()){
		cout<<ans.size()<<endl;
		reverse(ans.begin(),ans.end());
		for(int i: ans) cout<<i<<" ";
	}
	else cout<<"IMPOSSIBLE";
}
