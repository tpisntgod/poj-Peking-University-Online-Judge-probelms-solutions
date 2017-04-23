#include<iostream>

using namespace std;

int main()
{
	float f,t; int i;
	scanf("%f",&f);
	while (f)
	{
		t=0; i=2;
		while (t<f)
		{
			t=t+1.0/i;
			i++;
		}
		printf("%d card(s)\n",i-2);
		scanf("%f",&f);
	}
}
