#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100007;
struct data{
	int x,y,i;
} a[N];
int b[N],c[N];
int n,m;
bool cmp(const data & a,const data & b) {
	if (a.y==b.y) return a.x<b.x;
	return a.y>b.y;
}
int lowbit(int x) {
	return x&(-x);
}
int sum(int k) {
	int s=0;
	while(k>=1) {
		s+=c[k];
		k-=lowbit(k);
	}
	return s;
}
void add(int k,int s) {
	while(k<=m) {
		c[k]+=s;
		k+=lowbit(k);
	}
	return;
}
int main() {
	while(scanf("%d",&n) && n) {
		m=0;
		for (int i=1;i<=n;i++) {
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].x++; a[i].y++; a[i].i=i;
			if (a[i].x>m) m=a[i].x;
		}
		memset(c,0,sizeof(c));
		sort(a+1,a+1+n,cmp);
		b[a[1].i]=0; add(a[1].x,1);
		for (int i=2;i<=n;i++) {
			if (a[i].x==a[i-1].x && a[i].y==a[i-1].y)
				b[a[i].i]=b[a[i-1].i];
			else
				b[a[i].i]=sum(a[i].x);
			add(a[i].x,1);
		}
		for (int i=1;i<=n;i++)
			if (i<n) printf("%d ",b[i]);
			else printf("%d\n",b[i]);
	}
}
