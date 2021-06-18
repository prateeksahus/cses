#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin(),b.end());
	bool flag=0;
	int e,c;
	for(int i=0;i<n;i++){
		int d=abs(x-b[i]);
		if(binary_search(b.begin(),b.end(),d)){
			flag=1;
			e=b[i],c=d;
			break;
		}
	}
	bool f1=0,f2=0;
	if(flag==0||n<2) cout<<"IMPOSSIBLE";
	else{
		int x,y;
		for(int i=0;i<n;i++){
			if(a[i]==e&&!f1){
				x=i;
				++x;
				f1=1;
				continue;
			}
			if(a[i]==c&&!f2){
				y=i;
				++y;
				f2=1;
			}
		}
		if(!f1||!f2) cout<<"IMPOSSIBLE";
		else cout<<x<<" "<<y;
	}
}
