#include<iostream>
#include<algorithm>
using namespace std;

const int size=1007;
struct pix
{
	int pos;
	int c;
}
outmap[size*8];
int inmap[size][2];
int width,cntp,tot;

int getnum(int pos)
{
	int t=0,k=0;
	while (pos>t)
	{
		t+=inmap[k++][1];
	}
	return inmap[k-1][0];
}
int abss(int x)
{
	if (x<0) x=-x;
	return x;
}
int getvalue(int pos)
{
	int num=getnum(pos), k=0,max=0;
	int row=(pos-1)/width;
	int col=(pos-1)%width;
	for (int i=row-1;i<=row+1;i++)
		for (int j=col-1;j<=col+1;j++)
		{
		int tp=i*width+j;
		if (i<0 || j<0 || j>=width || tp>=tot) continue;
		k=abss(getnum(tp+1)-num);
		if (k>max) max=k;
	    }
	return max;
}
int cmp(pix x,pix y)
{
	return x.pos<y.pos;
}
int main()
{
	int num,len;
	while (scanf("%d",&width) && width>0)
	{
		cntp=0; tot=0;
		while (scanf("%d%d",&num,&len) && len>0)
		{
			inmap[cntp][0]=num;
			inmap[cntp++][1]=len;
			tot+=len;
		}
		printf("%d\n",width);
		
		int pos=1, k=0;
		
		for (int p=0;p<=cntp;p++)
		{
			int row=(pos-1)/width;
			int col=(pos-1)%width;
			for (int i=row-1;i<=row+1;i++)
			  for (int j=col-1;j<=col+1;j++)
			  {
			  	int tp=i*width+j;
			  	if (i<0 || j<0 || j>=width || tp>=tot) continue;
			  	outmap[k].pos=tp+1;
			  	outmap[k++].c=getvalue(tp+1);
			  }
			pos+=inmap[p][1];
		}
		
		sort(outmap,outmap+k,cmp);
	
		pix now=outmap[0];
		for (int i=0;i<k;i++)
		{
			if (outmap[i].c!=now.c)
			{
				printf("%d %d\n",now.c,outmap[i].pos-now.pos);
				now=outmap[i];
			}
		}
		printf("%d %d\n",now.c,tot-now.pos+1);
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}
