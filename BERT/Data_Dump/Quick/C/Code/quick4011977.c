#include <stdio.h>
#define INFTY 2000000000
#define MAX 500000
struct card{
	char mark;
	int number;
};

struct card L[MAX/2+2];
struct card R[MAX/2+2];

int partition(struct card *B,int p,int r){
	int i,j;
	struct card tmp;
	struct card parti;
	parti=B[r];// partition
	i=p-1;
	for(j=p;j<r;j++){
		if(B[j].number<=parti.number){
			i++;
			tmp=B[i];
			B[i]=B[j];
			B[j]=tmp;
		}
	}
	
	tmp=B[i+1];
	B[i+1]=B[r];
	B[r]=tmp;
	
	return i+1;
	
}

void quicksort(struct card *B,int p, int r){
	int q;
	if(p<r){
		q=partition(B,p,r);
		quicksort(B,p,q-1);
		quicksort(B,q+1,r);
	}
}

void merge(struct card *A,int n, int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++){
		L[i]=A[left+i];
	}
	for(int i=0;i<n2;i++){
	
		R[i]=A[mid+i];
	}
	
	L[n1].number=R[n2].number=INFTY;
	int i=0,j=0;
	
	for(int k=left;k<right;k++){
		if(L[i].number<=R[j].number){
			A[k]=L[i++];
		}
		else{
			A[k]=R[j++];
		}
	}
}

void mergesort(struct card  *A,int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergesort(A,n,left,mid);
		mergesort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}




void check(struct card *A,struct card *B,int n){
	int count=0;
	int i;
	for(i=0;i<n;i++){
		if(A[i].mark !=B[i].mark){
			count++;
			}
	}
	
	if(count==0){
			printf("Stable\n");
			}
		else{
			printf("Not stable\n");
			}
}



int main(void){
	int i,n;
	scanf("%d",&n);
	char S[2];
	struct card A[n];
	struct card B[n];
	
	for(i=0;i<n;i++){
		scanf("%s %d",&S,&(A[i].number));
		A[i].mark=S[0];//入力の時に空白も入力するのでCharを作って一番目だけをmarkに代入させる
		B[i]=A[i];
		
		}
	mergesort(A,n,0,n);
	quicksort(B,0,n-1);
	check(A,B,n);
	
	for(i=0;i<n;i++){
		printf("%c %d\n",B[i].mark,B[i].number);
	}
	return 0;
}
