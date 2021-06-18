#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	multiset<int> s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.insert(t);
	}
	ll c=0,ans=0;
	while(!s.empty()){
		if(c==0){
			c=x-*s.begin();
			++ans;
			s.erase(s.begin());
		}else{
			multiset<int>::iterator it = s.lower_bound(c);
			if(it==s.begin()&&*it>c){
				++ans;
				c=0;
				s.erase(s.begin());
				continue;
			}
			if(it==s.end()||*it>c){
				--it;
			}
			s.erase(it);
			c=0;
		}
	}
	cout<<ans;
}
