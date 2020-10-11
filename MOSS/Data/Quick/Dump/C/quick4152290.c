#include <stdio.h>
#define MAX 100000

int n;

struct card
{
	char suit;
	int value;
};

struct card L[MAX/2+2],R[MAX/2+2];

void merge(struct card A[],int left,int mid,int right){
	int n1,n2,i,j,k;
	struct card s,t;
	n1=mid-left;
	n2=right-mid;
	for(i=0;i<n1;i++)
		L[i]=A[left+i];
	for(i=0;i<n2;i++)
		R[i]=A[mid+i];
	L[n1].value=2000000000;
	R[n2].value=2000000000;
	i=j=0;
	for(k=left;k<right;k++){
		if(L[i].value<=R[j].value){
			A[k]=L[i];
			i=i+1;
		}
		else{
			A[k]=R[j];
			j=j+1;
		}
	}
}

void mergeSort(struct card A[],int left,int right){
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int partition(struct card A[],int p,int r){
	int i,j;
	struct card t,s,x;
	x=A[r];
	i=p-1;
	for(j=p;j<r;j++){
		if(A[j].value<=x.value){
			i=i+1;
			s=A[i];
			A[i]=A[j];
			A[j]=s;
		}	
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;
}

void quicksort(struct card A[],int p,int r){
	int q;
	if(p<r){
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main(){
	int i,v,stable=1;
	struct card A[MAX],B[MAX];
	char S[10];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s%d",S,&v);
		B[i].suit=A[i].suit=S[0];
		B[i].value=A[i].value=v;
	}
	mergeSort(A,0,n);
	quicksort(B,0,n-1);
	for(i=0;i<n;i++){
		if(A[i].suit!=B[i].suit)
			stable=0;
	}
	if(stable==1)
		printf("Stable\n");
	else
		printf("Not stable\n");
	for(i=0;i<n;i++)
		printf("%c %d\n",B[i].suit,B[i].value);
	return 0;
}
