#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

#define N 1000000
#define M 10000

using namespace std;

string w;
int next[M+2];
string t;

void getnext(void) {
	next[0]=0;
	int l=w.length();
	for (int i=1 , k=0; i<l; i++) {
		while (k>0 && w[i]!=w[k])
		    k = next[k-1];
		if (w[i] == w[k])
		    k++;
		next[i] = k;
	}
}

int count() {
	int s=0,lt=t.length(),lw=w.length();
	for (int i=0 , k=0; i<lt; i++) {
		while (k>0 && w[k]!=t[i])
		    k = next[k-1];
		if (w[k] == t[i])
		    k++;
		if (k == lw) {
		    s++;
		    k = next[k-1]; 
		}
	}
	return s;
}

int main() {
	int c;
	char ch;
	scanf("%d",&c);
	scanf("%c",&ch);
	while(c--) {
		getline(cin,w);
		getline(cin,t);
		getnext();
		int k=count();
		printf("%d\n",k);
	}
}
