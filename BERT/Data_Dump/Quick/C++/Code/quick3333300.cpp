#include<stdio.h>
#define M 100000
#define MM 2000000000
struct card{
	char suit;
	int num;
}L[M/2+2],R[M/2+2];
card A[M],B[M];
int partition(card B[],int p,int r){
	int x=B[r].num;
	int i=p;
	for(int j=p;j<r;j++){
		if(B[j].num<=x){
			card tmp=B[i];
			B[i]=B[j];
			B[j]=tmp;
			i++;
		}
	}
	card temp=B[i];
	B[i]=B[r];
	B[r]=temp;
	return i;
}

void qsrt(card B[],int p,int r){
	if(p<r){
		int q=partition(B,p,r);
		qsrt(B,p,q-1);
		qsrt(B,q+1,r);
	}
}

void merge(card A[],int l,int r){
	int m=(l+r)/2;
	int n1=m-l;
	int n2=r-m;
	int i;
	for(i=0;i<n1;i++) L[i]=A[l+i];
	for(i=0;i<n2;i++) R[i]=A[m+i];
	L[n1].num=R[n2].num=MM;
	int j=0;
	i=0;
	for(int k=l;k<r;k++){
		if(L[i].num<=R[j].num) A[k]=L[i++];
		else A[k]=R[j++];
	}
}

void mergesort(card A[],int l,int r){
	if(l+1<r){
		int m=(l+r)/2;
		mergesort(A,l,m);
		mergesort(A,m,r);
		merge(A,l,r);
	}
}

int main(){
	int i,n,j,k;

	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		scanf("%c %d",&A[i].suit,&A[i].num);
		getchar();
	} 
	for(i=0;i<n;i++) B[i]=A[i];
	mergesort(A,0,n);
	qsrt(B,0,n-1);
	int judge=1;
	for(i=0;i<n;i++){
		if(A[i].suit != B[i].suit){
			judge=0;
			break;
		}
	}
	if(judge) printf("Stable\n");
	else printf("Not stable\n");
	//for(i=0;i<n;i++){
	//	printf("%c %d\n",A[i].suit,A[i].num);
	//}
	for(i=0;i<n;i++){
		printf("%c %d\n",B[i].suit,B[i].num);
	}
}
