#include <bits/stdc++.h>
using namespace std;
int A[2000001],B[2000001];
void CountingSort(int n,int k)
{
	int C[k+1]={0};
	for(int j=1;j<=n;j++)
		C[A[j]]++;
	for(int i=1;i<=k;i++)
		C[i] += C[i-1];
	for(int j=1;j<=n;j++){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}
int main()
{
	int n,k=0; 
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		k = max(k,A[i]);
	}
	CountingSort(n,k);
	for(int i=1;i<=n;i++)
		if(i==n) printf("%d\n",B[i]);
		else printf("%d ",B[i]);
	return 0;
}
