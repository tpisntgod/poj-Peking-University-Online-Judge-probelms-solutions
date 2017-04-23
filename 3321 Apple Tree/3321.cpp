#include<cstdio>
#include<iostream>

using namespace std;

const int N=100007;
struct node{
	int to,next;
} a[N];
int ls[N],b[N],c[N],l[N],r[N];
int n,q,e,h;
void dfs(int k) {
	h++;
	l[k]=h;
	for (int i=ls[k];i;i=a[i].next) {
		dfs(a[i].to);
	}
	r[k]=h;
}
int lowbit(int k) {
	return k&(-k);
	//return k&(k^(k-1));
}
void add(int k,int s) {
	while(k<=n) {
		c[k]+=s;
		k+=lowbit(k);
	}
}
int sum(int k) {
	int l=0;
	while(k>=1) {
		l+=c[k];
		k-=lowbit(k);
	}
	return l;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		a[++e].to=v; a[e].next=ls[u]; ls[u]=e;
	}
	dfs(1);
	for (int i=1;i<=n;i++) {
		b[i]=1;
		add(i,1);
	}
	char cc;
	scanf("%d%c",&q,&cc);
	for (int i=1;i<=q;i++) {
		char c1,c2,c3;
		int k;
		scanf("%c%c%d%c",&c1,&c2,&k,&c3);
		if (c1=='Q') {
			printf("%d\n",sum(r[k])-sum(l[k]-1));
		} else {
			b[k]=-b[k];
			add(l[k],b[k]);
		}
	}
}
