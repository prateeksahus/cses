//floyd warshall
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mxn = 501;
int n,m,q;
vector<vector<ll>> dist(mxn, vector<ll>(mxn, (ll)INT_MAX*501));

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dist[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		dist[a][b] = min(dist[a][b], (ll)c);
		dist[b][a] = min(dist[b][a], (ll)c);
	}
	floyd();
	while(q--){
		int a,b;
		cin>>a>>b;
		if(dist[a][b]==(ll)INT_MAX*501) cout<<-1<<endl;
		else cout<<dist[a][b]<<endl;
	}
}
