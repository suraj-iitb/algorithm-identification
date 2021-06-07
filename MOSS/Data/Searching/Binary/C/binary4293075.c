#include<stdio.h>
int sum;
int binary_me(int A[],int n,int x){
	int f=0,b=n-1;
	int p;
	while (f<=b){
		p=(f+b)/2;
		if(A[p]>x){b=p-1; continue;}
		else if(A[p]<x) {f=p+1;continue;}
		else return 1;}
	return 0;
}
			
int L[100005],S[50005];
int main(){
	int n,q;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",L+i);
	scanf("%d",&q);
	for(int i=0;i<q;++i)
		scanf("%d",S+i);

	int numb=0;
	while(numb<q){
		if(binary_me(L,n,S[numb]))
			++sum;
		++numb;}
	printf("%d\n",sum);
	return 0;
}
