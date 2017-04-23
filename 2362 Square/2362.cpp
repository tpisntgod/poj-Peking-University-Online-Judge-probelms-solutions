#include<iostream>
#include<cstring>

using namespace std;

int a[22],b[22],p,n,m,s,pd;

void pdd(int k,int l,int h)
{
	if (pd) return;
	if (k==3)
	{
		pd=1;
	    return;
    }
	for (int i=h;i<=m;i++)
	if (b[i]==0 && a[i]+l<=p)
	{
		b[i]=1;
		if (a[i]+l==p)	pdd(k+1,0,1);
		  else pdd(k,l+a[i],i+1);
		b[i]=0;
		if (pd) return;
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		s=0; pd=0;
		scanf("%d",&m);
		memset(b,0,sizeof(b));
		for (int j=1;j<=m;j++)
		{
		    scanf("%d",&a[j]);
		    s+=a[j];
		}
		p=s/4;
		if (s%4!=0) printf("no\n");
		else 
		{
		  pdd(0,0,0);
		  if (pd) printf("yes\n"); 
		    else printf("no\n");
	    }
	}
}
