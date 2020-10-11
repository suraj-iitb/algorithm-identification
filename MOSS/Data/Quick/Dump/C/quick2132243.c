#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}

typedef struct{
	long key;
	long order;
	char suit;
}data;

data *readData(long n){
	long i,j;
	char c;
	data *A;
	mymalloc(A,n);
	for(i=0;i<n;i++){
		scanf(" %c %ld",&c,&j);
		A[i].key=j;
		A[i].order=i;
		A[i].suit=c;
	}
	return A;
}

void swap(data *i,data *j){
	data tmp;
	tmp=*i;
	*i=*j;
	*j=tmp;
}

long partition(data *A,long p,long r){
	long i,j,x;
	x=A[r].key;
	i=p;
	for(j=p;j<r;j++){
		if(A[j].key<=x){
			swap(&A[i],&A[j]);
			i++;
		}
	}
	swap(&A[i],&A[r]);
	return i;
}

void quickSort(data *A, long p, long r){
	long q;
	if(p<r){
		q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int checkStab(data *A,long n){
	long i,k1,k2,o1,o2;
	k1=A[0].key;
	o1=A[0].order;
	for(i=1;i<n;i++){
		k2=A[i].key;
		o2=A[i].order;
		if(k1==k2&&o1>o2){
			return 1;
		}
		k1=k2;
		o1=o2;
	}
	return 0;
}
				

void printData(data *A,long n,int s){
	long i;
	if(s==0){
		printf("Stable\n");
	}
	if(s==1){
		printf("Not stable\n");
	}
	for(i=0;i<n;i++){
		printf("%c %ld\n",A[i].suit,A[i].key);
	}
}

main(){
	int s;
	long p,n;
	data *A;
	scanf("%ld",&n);
	A=readData(n);
	quickSort(A,0,n-1);
	s=checkStab(A,n);
	printData(A,n,s);
	free(A);
	return 0;
}
