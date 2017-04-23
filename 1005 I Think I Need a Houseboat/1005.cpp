#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n,a;
	float x,y,k;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%f%f",&x,&y);
		k=x*x+y*y;
		k=k*3.1415926/2;
		a=k/50;
		printf("Property %d: This property will begin eroding in year %d.\n",
		i,a+1);
	}
	printf("END OF OUTPUT.\n");
}
