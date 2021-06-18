#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> b(m);
	multiset<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.insert(x);
	}
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<m&&!a.empty();i++){
		multiset<int>::iterator it = a.lower_bound(b[i]);
		if(it==a.end()){
			--it;
			cout<<*it<<endl;	
			a.erase(it);
			continue;
		}
		if(*it==b[i]){
			cout<<b[i]<<endl;
			a.erase(it);
			continue;
		}
		if(*it>b[i]&&it!=a.begin()){
			--it;
			cout<<*it<<endl;
			a.erase(it);
			continue;
		}
		cout<<-1<<endl;
	}
	if(m>n)
		for(int i=0;i<m-n;i++) cout<<-1<<endl;
}
