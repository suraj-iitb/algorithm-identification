#include<stdio.h>
#include<limits.h>

typedef struct{
	char suit;
	int value;
}Card;

int partition(Card *,int,int);
void merge(Card *,int,int,int);
void mergeSort(Card *,int,int,int);
void quickSort(Card *,int,int,int);

Card L[50002],R[50002];

int main(){
	int n,i,v;
	Card A[100000],B[100000];
	char S;
	int hantei=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %c",&S);
		scanf("%d",&v);
		A[i].suit=B[i].suit=S;
		A[i].value=B[i].value=v;
	}
	mergeSort(A,n,0,n);
	quickSort(B,n,0,n-1);
	for(i=0;i<n;i++){
		if(A[i].suit!=B[i].suit)hantei=0;
	}
	if(hantei==1)printf("Stable\n");
	else printf("Not stable\n");
	for(i=0;i<n;i++){
		printf("%c %d\n",B[i].suit,B[i].value);
	}
	return 0;
}

int partition(Card *A,int p,int r){
  int i,j;
  Card x,a;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      a=A[i];
      A[i]=A[j];
      A[j]=a;
    }
  }
  a=A[i+1];
  A[i+1]=A[r];
  A[r]=a;
  return i+1;
}

void merge(Card *A,int left,int mid,int right){
	int i,j,k;
	int n1 = mid-left;
	int n2 =right-mid;
	for(i=0;i<n1;i++) L[i]=A[left+i];
	for(i=0;i<n2;i++) R[i]=A[mid+i];
	L[n1].value=R[n2].value=INT_MAX;
	i=0;
	j=0;
	for(k=left;k<right;k++){
		if(L[i].value<=R[j].value){
			A[k]=L[i++];
		}
		else{
			A[k]=R[j++];
		}
	}
}

void mergeSort(Card *A,int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,left,mid,right);
  }
}

void quickSort(Card *A,int n,int p,int r){
	int q;
	if(p<r){
		q=partition(A,p,r);
		quickSort(A,n,p,q-1);
		quickSort(A,n,q+1,r);
	}
}

