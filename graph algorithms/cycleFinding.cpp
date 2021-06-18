//bellman ford for finding negative cycle
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 2500, mxm = 5000;
int n,m;
vector<array<ll,3>> e;
vector<ll> dist(mxn);
map<int, int> par;

void bellman_ford(){
	for(int i=0;i<n;i++){
		int x = -1;
		for(array<ll,3> v : e){
			if(dist[v[0]]+v[2]<dist[v[1]]){
				dist[v[1]] = dist[v[0]]+v[2];
				par[v[1]] = v[0]; //storing the relaxing node
				x = v[1];		//storing the latest node
				if(i==n-1){
					//going to the negative cycle
					for(int j=0;j<n;j++){ 
						x = par[x];		
					}
					vector<int> ans;
					//storing the cycle in vector
					for(int p=x; ;p=par[p]){
						ans.push_back(p);
						if(p==x and ans.size()>1) break;
					}
					reverse(ans.begin(), ans.end());
					cout<<"YES"<<endl;
					for_each(ans.begin(), ans.end(), [](int q){
										cout<<q+1<<" ";
									});
					return;
				}
			}
		}
	}
	cout<<"NO";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		--a, --b;
		e.push_back({a, b, c});
	}
	bellman_ford();
}
