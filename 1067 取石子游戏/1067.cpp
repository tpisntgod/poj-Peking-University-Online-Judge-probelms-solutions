#include<iostream>
#include<algorithm>
#include<cmath>

int main()
{
	int a,b,t,l;
	while (scanf("%d%d",&a,&b)==2)
	{
		if (a>b)
		{
			t=a; a=b; b=t;
		}
		t=b-a;
		l=floor(t*(sqrt(5.0)+1)/2);
		if (l==a) printf("0\n"); else printf("1\n");
	}
}
