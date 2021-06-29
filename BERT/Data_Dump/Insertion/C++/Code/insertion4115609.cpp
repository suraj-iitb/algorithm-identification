//By Vlgd
#include<bits/stdc++.h>
using namespace std;
int A[100];
void s(int n){
	for (int i=0;i<n;i++){
		printf("%d",A[i]);
		if(i==n-1)printf("\n");
		else printf(" ");
	}
}
int main(){
	int n;scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);s(n);
	for (int i=1;i<n;i++){
		int j=i-1,v=A[i];
		while (j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		s(n);
	}
}
