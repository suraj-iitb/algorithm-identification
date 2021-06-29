#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
const int MAXN = 2000000+7;
using namespace std;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int n;
void countSort(){
	memset(c, 0, sizeof(int)*MAXN);
	int maxm;
	for(int i = 0; i < n; i++){
		if(i == 0) maxm = a[i];
		else maxm = max(maxm,a[i]);
		c[a[i]] += 1;
	}
	for(int i = 1; i <= maxm; i++){
		c[i] = c[i-1] + c[i];
	}
	for(int i = n-1; i >= 0; i--){
		b[c[a[i]]-1] = a[i];
		c[a[i]] -= 1;
	}
} 
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	countSort();
	for(int i = 0; i < n; i++){
		if(i!=0) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}
