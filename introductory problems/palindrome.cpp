#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	string s;
	cin>>s;
	string ans="";
	map<char,int> mp;
	for(char ch:s)
		++mp[ch];
	char p;
	int cnt=0;
	for(auto x:mp){
		if(x.second%2) ++cnt, p=x.first;
		int temp = x.second/2;
		while(temp--)
			ans.push_back(x.first);
	}
	if(cnt>1){
		cout<<"NO SOLUTION";
		return 0;
	}
	if(cnt==1)
		ans.push_back(p);
	map<char,int>::reverse_iterator rit;
	for(rit=mp.rbegin();rit!=mp.rend();rit++){
		int temp = rit->second/2;
		while(temp--)
			ans.push_back(rit->first);
	}
	cout<<ans;
}
