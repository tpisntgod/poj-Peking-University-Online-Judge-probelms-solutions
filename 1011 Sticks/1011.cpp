#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int a[67],b[67],p,n,s,pd,maxx;

void pdd(int k,int l,int h)
{
	if (pd) return;
	if (k==n)
	{
		pd=1;
	    return;
    }
	for (int i=h;i<n;i++)
	{
	if (b[i]) continue;
	if (b[i]==0 && a[i]+l<=p)
	{
		if (b[i-1]==0 && a[i]==a[i-1]) continue;
		b[i]=1;
		if (a[i]+l==p)	pdd(k+1,0,1);
		  else pdd(k+1,l+a[i],i+1);
		b[i]=0;
		if (pd) return;
	}
	if (l==0) return;
	}
	return;
}
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while (scanf("%d",&n) && n!=0)
	{
		memset(b,0,sizeof(b));
	    s=0; pd=0; maxx=0;
		for (int j=0;j<n;j++)
		{
		    scanf("%d",&a[j]);
		    if (a[j]>maxx) maxx=a[j];
		    s+=a[j];
		}
		sort(a,a+n,cmp);
	    for (int j=maxx;j<=s;j++)
		if (s%j==0)
		{
			p=j;
			pdd(0,0,0);
			if (pd)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
}
