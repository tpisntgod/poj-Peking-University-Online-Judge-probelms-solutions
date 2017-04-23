#include<iostream>
#include<string.h>
using namespace std;

int a[10000007];
int main()
{
	int n,t,pd=0;
	char s[107];
	cin>>n;
	for (int j=1;j<=n;j++)
	{
		scanf("%s",s);
		t=0;
		for (int i=0;i<strlen(s);i++)
		{
			if (s[i]>=48 && s[i]<=57)
			t=t*10+s[i]-48;
			switch (s[i])
			{
				case 'A':
				case 'B':
				case 'C': t=t*10+2; break;
				case 'D':
				case 'E':
				case 'F': t=t*10+3; break;
				case 'G':
				case 'H':
				case 'I': t=t*10+4; break;
				case 'J':
				case 'K':
				case 'L': t=t*10+5; break;
				case 'M':
				case 'N':
				case 'O': t=t*10+6; break;
				case 'P':
				case 'R':
				case 'S': t=t*10+7; break;
				case 'T':
				case 'U':
				case 'V': t=t*10+8; break;
				case 'W':
				case 'X':
				case 'Y': t=t*10+9; break;
			}
		}
		a[t]++;
	}
	for (int i=0;i<=9999999;i++)
	if (a[i]>1)
	{
		int x=i/10000, y=i%10000;
		printf("%03d-%04d %d\n",x,y,a[i]);
		pd=1;
	}
	if (pd==0) printf("No duplicates.\n");
}
