#include<iostream>

using namespace std;

int main()
{
	int a,b,c,d,k,i=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while (a!=-1 && b!=-1 && c!=-1 && d!=-1)
	{
		i++;
		k=d;
		while ((k-c)%33)
		  k++;
		while (1)
		{
			if ((k-a)%23==0 && (k-b)%28==0)
			{
				if ((k-d)==0) k+=21252;
				printf("Case %d: the next triple peak occurs in %d days.\n",i,k-d);
				break;
			}
			k+=33;
		}
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}
}
