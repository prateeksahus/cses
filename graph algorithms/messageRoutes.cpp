//bfs on graph ans printing the path
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj(1e5+1);
vector<int> path;
vector<int> dist(1e5+1, 1e9);
int n,m;

void bfs(int x){
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	map<int,int> mp;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int c : adj[s]){
			if(dist[c] == 1e9){
				dist[c] = dist[s]+1;
				mp[c] = s;
				if(c==n){
					int node = c;
					while(true){
						path.push_back(node);
						if(node == 1) break;
						node = mp[node];
					}
					return;
				}
				q.push(c);
			}
		}
	}
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
	bfs(1);
	if(path.size()==0) cout<<"IMPOSSIBLE\n";
	else{
		reverse(path.begin(),path.end());
		cout<<path.size()<<endl;
		for(int i : path)
			cout<<i<<" ";
	}
}
