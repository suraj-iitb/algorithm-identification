#include <bits/stdc++.h>
using namespace std;
int A[500000],cont=0;
void merge(int left,int mid,int right){
	int n1 = mid-left;
	int n2 = right-mid;
	int L[n1+1],R[n2+1];
	for(int i=0;i<n1;i++)
		L[i] = A[left+i];
	for(int i=0;i<n2;i++)
		R[i] = A[mid+i];
	L[n1] = R[n2] = 1e9+1;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		if(L[i]<=R[j]) A[k] = L[i++];
		else A[k] = R[j++];
		cont++;
	}
}
void ms(int left,int right){
	if(left+1<right){
		int mid = (left+right)/2;
		ms(left,mid);
		ms(mid,right);
		merge(left,mid,right);
	}
}
int main(){
	int n; cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	ms(0,n);
	for(int i=0;i<n;i++)
		if(i==0) printf("%d",A[i]);
		else printf(" %d",A[i]);
	printf("\n%d\n",cont);
    return 0;
}
