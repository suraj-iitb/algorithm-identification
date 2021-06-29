//By Vlgd
#include<bits/stdc++.h>
using namespace std;
int A[500000],cnt=0;
void merge(int T[],int l,int r,int mid){
	int a=mid-l,b=r-mid;
	int L[a+1],R[b+1];
	for(int i=0;i<a;i++) L[i]=T[i+l];
	for(int i=0;i<b;i++) R[i]=T[i+mid];
	L[a]=R[b]=1000000002;
	int i=0,j=0;
	for(int k=l;k<r;k++){
		if (L[i]<=R[j]) T[k]=L[i++];
		else T[k]=R[j++];
		cnt++;
	}
}
void msort(int T[],int l,int r){
	if (r-l>1){
		int mid=(l+r)/2;
		msort(T,l,mid);
		msort(T,mid,r);
		merge(T,l,r,mid);
	}
}
//void merge2(int A[],int x,int y,int T[]){
//	if(y-x>1){
//		int m=(x+y)/2;
//		int p=x,q=m,i=x;
//		merge2(A,x,m,T);
//		merge2(A,m,y,T);
//		while(p<m||q<y){
//			if (q>=y||(p<m&&A[p]<=A[q])) T[i++]=A[p++];
//			else T[i++]=A[q++];
//			cnt++;
//		}
//		for (int i=x;i<y;i++) A[i]=T[i];
//	}
//}
//void msort2(int A[],int n){
//	int T[n];
//	merge2(A,0,n,T);
//} 
main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	msort(A,0,n);
	for(int i=0;i<n;i++){
		printf("%d",A[i]);
		if(i!=n-1) printf(" ");
		else printf("\n");
	}
	printf("%d\n",cnt);
}

