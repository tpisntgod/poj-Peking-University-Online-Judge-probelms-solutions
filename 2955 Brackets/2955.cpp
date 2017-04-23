#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main() {
	char s[107];
	int dp[107][107];
	while(scanf("%s",s)) {
		if (s[0]=='e') break;
		int len=strlen(s);
		memset(dp,0,sizeof(dp));
		for (int i=1;i<len;i++) {  //枚举区间长度 
			for (int j=0,k=i;k<len;j++,k++) {
				if ( ( s[j]=='(' && s[k]==')' ) ||
				( s[j]=='[' && s[k]==']' ) )
					dp[j][k]=dp[j+1][k-1]+2;
				for (int l=j;l<k;l++)
					dp[j][k]=max(dp[j][k],dp[j][l]+dp[l+1][k]);
			}
		}
		printf("%d\n",dp[0][len-1]);
	}
}
