//dfs on graph
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

vector<vector<int>> adj(1e5+1);
vector<bool> vis(1e5+1,0);

void dfs(int n){
	vis[n] = 1;
	for(int child : adj[n]){
		if(!vis[child]){
			vis[child] = true;
			dfs(child);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int s, d;
		cin>>s>>d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	vector<int> roads;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cnt++;
			roads.push_back(i);
			dfs(i);
		}
	}
	cout<<--cnt<<endl;
	for(int i=1;i<roads.size();i++){
		cout<<roads[0]<<" "<<roads[i]<<endl;
	}
}
