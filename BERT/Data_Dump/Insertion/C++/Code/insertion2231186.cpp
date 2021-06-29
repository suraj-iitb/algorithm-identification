#include "bits/stdc++.h"
using namespace std;
int A[100];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	printf("%d",A[0]);
	for(int i=1;i<n;i++) printf(" %d",A[i]);
	printf("\n");
	for(int i=1;i<n;i++) {
		int j=i-1;
		int v=A[i];
		while(j>=0&&A[j]>v) {
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		printf("%d",A[0]);
		for(int i=1;i<n;i++) printf(" %d",A[i]);
		printf("\n");
	}
}
