#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

const int N=100007;
int a[N][20],b[N];
int n,q;

void rmq() {
	for (int j=1; (1<<j) <=n; j++)
		for(int i=1; i+ (1<<j) -1 <=n; i++) {
			a[i][j]=max(a[i][j-1],a[i+ ( 1<<(j-1) )][j-1]);
			int k1=i+ ( 1<<(j-1) ) -1,l=i,r=i+ (1<<j) -1;
			int h=b[k1],k2=k1;
			while(b[k1]==h && k1 >= l) k1--;
			while(b[k2]==h && k2 <= r) k2++;
			if (k2-k1-1 > a[i][j]) a[i][j]=k2-k1-1;
		}
}
int getans(int l,int r) {
	int k=(int) (log(r-l+1.0) / log(2.0));
	int s=max(a[l][k],a[r- (1<<k) +1][k]);
	int p1=l+ (1<<k) -1;
	int p2=p1,h=b[p1];
	while(b[p1]==h && p1>=l) p1--;
	while(b[p2]==h && p2<=r) p2++;
	int s2=p2-p1-1;
	if (s2>s) return s2; else return s;
}
int main() {
	while(scanf("%d",&n) && n) {
		scanf("%d",&q);
		for (int i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			a[i][0]=1;
		}
		rmq();
		while(q--) {
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",getans(l,r));
		}
	}
}
