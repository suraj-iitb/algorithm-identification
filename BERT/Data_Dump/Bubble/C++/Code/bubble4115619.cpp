//By Vlgd
#include<bits/stdc++.h>
using namespace std;
int A[100];
int main(){
	int n,cnt=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&A[i]);
	for(int i=n-1;i>=0;i--){
		int flg=0;
		for (int j=0;j<i;j++)
			if (A[j]>A[j+1]){
				swap(A[j],A[j+1]);
				flg=1;cnt++;
			}
		if (!flg) break;
	}
	for (int i=0;i<n;i++){
		printf("%d",A[i]);
		if (i==n-1) printf("\n");
		else printf(" ");
	}
	printf("%d\n",cnt);
}
