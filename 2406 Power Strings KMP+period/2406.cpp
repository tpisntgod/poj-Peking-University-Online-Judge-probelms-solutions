#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

char s[1000007];
int next[1000007];

void getnext(void){
	int l=strlen(s);
	next[0]=0;
	for (int i=1, k=0; i<l; i++) {
		while (k>0 && s[i] != s[k])
			k = next[k-1];
		if (s[k] == s[i])
			k++;
		next[i] = k;
	}
	int h=l-next[l-1];
	int a=l/h;
	if (l%h == 0) printf("%d\n",a);
		else printf("1\n");
}

int main() {
	scanf("%s",s);
	while (strcmp(s,".")!=0) {
		getnext();
		scanf("%s",s);
	}
	return 0;
}
