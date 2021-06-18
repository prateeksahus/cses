//bfs on 2d grid and printing the path
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<char>> grid(1000, vector<char>(1000));
vector<vector<bool>> vis(1000, vector<bool>(1000,0));
int n,m,stx,sty;// stx- start x coordinate, sty- start y coordinate

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char moves[] = {'U', 'R', 'D', 'L'};//array for direction taken in grid in sync with the above two arrays

string bfs(int x, int y){
	string path = "";	//initializing the path
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y] = 1;
	auto is_valid = [](int x, int y){	//checks if it is possible to go to that position
			return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]!='#';
		};
	map<pair<int,int>, pair<pair<int,int>,char>> par;	//used for backtracking
	// it maps the coordinate of current node to its parent node and the direction by which par can reach the child
	// here direction is the moves char array
	while(!q.empty()){
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int newx = sx+dx[i];
			int newy = sy+dy[i];
			if(is_valid(newx, newy)){
				vis[newx][newy] = 1;
				par[{newx, newy}] = {{sx, sy}, moves[i]};	//here we map child to its parent
				if (grid[newx][newy] == 'B') {		//backtracking starts when we have reached the destination i.e B
					pair<int,int> node = {newx, newy};	//storing the current node in node which will change in the while loop
					while(true){
						path += par[node].second;	//we store the moves in the path string
						node = par[node].first;		//then we set the current node to parent node and the loop continues;
						if(node.first==stx && node.second==sty){	//backtracking ends when we reach the start node
							reverse(path.begin(),path.end());	//due to backtracking the path is in reverse order so we reverse it
							return path;
						}
					}	
				}
				q.push({newx, newy});	
			}
		}
	}
	return path;	//in this case the path is empty
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
			if(grid[i][j] == 'A') stx = i, sty = j;	//storing the position of A in start variables
		}
	string path = bfs(stx, sty);// bfs returns the path string
	if(path.size()==0)
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		cout<<path.size()<<endl;
		cout<<path;	
	}
}
