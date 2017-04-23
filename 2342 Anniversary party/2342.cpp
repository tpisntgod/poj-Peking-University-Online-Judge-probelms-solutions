#include<iostream>
#include<algorithm>
using namespace std;

int n,root=0;
int a[6007][2],f[6007],v[6007];
void tree_dp(int k)
{
	v[k]=1;
	for (int i=1;i<=n;i++)
	  if (v[i]==0 && f[i]==k)
	  {
	  	//v[i]=1;
	  	tree_dp(i);
	  	a[k][0]+=max(a[i][0],a[i][1]);
	  	a[k][1]+=a[i][0];
	  }
}
int main()
{
	int x,y;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i][1]);
	while (scanf("%d%d",&x,&y))
	{
		f[x]=y;
		if (x==0 && y==0) break;
	}
	for (int i=1;i<=n;i++)
	  if (f[i]==0)
	  {
	  	root=i;
	  	break;
	  }
	tree_dp(root);
	int ans=max(a[root][0],a[root][1]);
	printf("%d\n",ans);
}
