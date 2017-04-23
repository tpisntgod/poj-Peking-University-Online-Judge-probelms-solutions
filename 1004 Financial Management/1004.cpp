#include<iostream>

using namespace std;

int main()
{
	float b,s=0.0;
	for (int i=1;i<=12;i++)
	{
		scanf("%f",&b);
		s+=b;
	}
	printf("$%.2f\n",s/12.0);
}
