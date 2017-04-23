#include<cstdio>
#include<cstring>
using namespace std; 

int c[1027][1027];
int n;
int lowbit(int x){
	return x&-x;
}
void add(int x,int y,int s){
	for (int i=x;i<=n;i+=lowbit(i))
	    for (int j=y;j<=n;j+=lowbit(j))
	        c[i][j]+=s;
}
int query(int x,int y){
	int s=0;
	for (int i=x;i>=1;i-=lowbit(i))
	    for (int j=y;j>=1;j-=lowbit(j))
	        s+=c[i][j];
	return s;
}
int main(){
	int k;
	scanf("%d%d",&k,&n);
	n++;
	while (k!=3){
		scanf("%d",&k);
		if (k==1){
			int x,y,a;
			scanf("%d%d%d",&x,&y,&a);
			x++; y++;
			add(x,y,a);
		};
		if (k==2){
			int l,b,r,t;
			scanf("%d%d%d%d",&l,&b,&r,&t);
			l++; b++; r++; t++;
			int ans=query(r,t)+query(l-1,b-1)-query(r,b-1)-query(l-1,t);
			printf("%d\n",ans);
		}
	}
}
