//By Vlgd
#include<bits/stdc++.h>
using namespace std;
const int K=10001;
int A[2000001],C[2000001];
int buck[K]={0};
main(){
	int n;scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&A[i]);
		buck[A[i]]++;
	}
	for (int i=1;i<=K;i++) buck[i]+=buck[i-1];
	for (int i=n-1;i>=0;i--){
		C[buck[A[i]]]=A[i];
		buck[A[i]]--;
	}	
	for (int i=1;i<=n;i++){
		printf("%d",C[i]);
		if (i!=n) printf(" ");
		else printf("\n");
	}
}

