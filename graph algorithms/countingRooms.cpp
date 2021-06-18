//dfs on 2d grid
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<char>> grid(1000, vector<char>(1000));
vector<vector<bool>> vis(1000, vector<bool>(1000,0));
int n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
	vis[x][y] = 1;
	auto is_valid = [](int x, int y){
		return x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]!='#';
		};
	for(int i=0;i<4;i++){
		if(is_valid(x+dx[i], y+dy[i]))
			dfs(x+dx[i], y+dy[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]!='#' && !vis[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
}
