#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
#define maxl 297
using namespace std;

int main() {
	string s,s2;
	int ans,t;
	int a[maxl];
	char ch;
	priority_queue<int,vector<int>,greater<int> > q;
	getline(cin,s);
	s2="END";
	while(s!=s2) {
		t=8*s.length();
		ans=0;
		memset(a,0,sizeof(a));
		for (int i=0;i<s.length();i++) 
			a[s[i]]++;
		for (int i=0;i<maxl;i++)
			if (a[i]!=0) q.push(a[i]);
		while(q.size()!=1) {
			int a=q.top(); q.pop();
			int b=q.top(); q.pop();
			ans+=(a+b);
			q.push(a+b);
		}
		while(!q.empty())
			q.pop();
		if (ans == 0) ans=s.length();
		printf("%d %d %.1f\n",t,ans,double(1.0*t/ans));
		getline(cin,s);
	}
	
}
