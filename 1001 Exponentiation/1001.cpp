#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int po;
int a[207],b[207],c[207],la,lb,l,lr;
void cheng()
{
	memset(c,0,sizeof(c));
	for (int i=1;i<=la;i++)
	{
		for (int j=1;j<=lb;j++)
		{
			c[i+j-1]=c[i+j-1]+a[i]*b[j];
			c[i+j]=c[i+j]+c[i+j-1]/10;
			c[i+j-1]=c[i+j-1]%10;
		}
	}
	for (int i=206;i>=1;i--)
	  if (c[i]!=0)
	  {
	  	la=i;
	  	break;
	  }
	for (int i=1;i<=la;i++)
	  a[i]=c[i];
}
int main()
{
	char s[10];
	int n;
	while (scanf("%s%d",s,&n)==2)
	{
	    memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
		po=-1;
		int j=1;
		for (int i=5;i>=0;i--)
		{
		  if (s[i]!='.')
		  {
		  	a[j]=b[j]=s[i]-48;
		  	j++;
		  }
		  if (s[i]=='.') po=5-i;
	    }
		if (po==-1) la=lb=6;
		else la=lb=5;
		for (int i=1;i<n;i++)
		  cheng();
		po=po*n;
		for (int i=206;i>=1;i--)
		  if (a[i]!=0)
		  {
		  	l=i;
		  	break;
		  }
		if (po>l)
		{
			printf(".");
		    for (int i=po;i>l;i--)
		      printf("0");
	    }
	    lr=-1;
	    for (int i=1;i<=po;i++)
	      if (a[i]!=0)
	      {
	      	lr=i;
	      	break;
		  }
		if (lr==-1) lr=po+1;
		for (int i=l;i>=lr;i--)
		{
			if (i==po) printf(".");
			printf("%d",a[i]);
		}
		printf("\n");
	}
}
