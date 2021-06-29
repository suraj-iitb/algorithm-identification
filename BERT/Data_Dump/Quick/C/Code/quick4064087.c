#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000001

typedef struct{ //構造体
		int value;
		char key;
} Card;

int partition(Card *A, int  p, int r){
	int i, j, x;
	Card temp;
	x = A[r].value;
	//printf("x:%d\n", x);
	i = p-1;
	for(j=p; j<r; j++){
		if(A[j].value<=x){
			i=i+1;
			//A[i] と A[j] を交換
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	//A[i+1] と A[r] を交換
	temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	
	return i+1;
}

void quicksort(Card *A, int  p, int r){
	int q;
	if(p<r){
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}
void merge(Card *B, int left, int mid, int right) //merge で統治
{
	int n1, n2;
	Card *L, *R;
	L=malloc(sizeof(Card)*right);
	R=malloc(sizeof(Card)*right);
	int i, j, k;
	n1=mid-left;
	n2=right-mid;
	//L[0...n1], R[0...n2] を生成
	for(i=0; i<n1; i++) L[i]=B[left+i];
	for(i=0; i<n2; i++) R[i]=B[mid+i];
	L[n1].value=INFTY;
	R[n2].value=INFTY;
	i=0;
	j=0;
	for(k=left; k<right; k++){
		if(L[i].value<=R[j].value){
			B[k]=L[i];
			i=i+1;
		}
		else{
			B[k]=R[j];
			j=j+1;
		}
	}
	
	free(L);
	free(R);
}

void mergeSort(Card *B, int left, int right) //mergeSort で分割. 部分配列の要素数が 1 以下のときは何もせず終了
{
	//部分配列の中央の位置 mid
	//部分配列の前半部分は left から mid （ mid は含まない
	//後半部分は mid から right （ right は含まない）
	int mid;
	if(left+1<right){
		mid=(left+right)/2;
		mergeSort(B, left, mid);
		mergeSort(B, mid, right);
		merge(B, left, mid, right);
	}
}

int main(void){
	int i, n, no=0;
	Card *A, *B;
	scanf("%d", &n);
	A=malloc(sizeof(Card)*n);
	B=malloc(sizeof(Card)*n);
	for(i=0; i<n; i++){
		scanf(" %c %d", &A[i].key, &A[i].value);
		B[i]=A[i];
	}
	
	quicksort(A, 0, n-1);
	mergeSort(B, 0, n);
	for(i=0; i<n; i++){
		if(B[i].key!=A[i].key){
			no=1;
			break;
		}
	}
	if(no) printf("Not stable\n");
	else printf("Stable\n");
	for(i=0; i<n; i++) printf("%c %d\n", A[i].key, A[i].value);
	
	free(A);
	free(B);
	return 0;
}
