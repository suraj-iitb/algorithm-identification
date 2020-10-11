#include<stdio.h>

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void move(int *num,int *j,int *stop){
	int i,temp;

	for(i=*stop-1;i>=*j;i--){
		temp=*(num+i);
		*(num+i+1)=temp;
	}
}

void change(int *num,int *n){
	int i,j,temp;
	
	for(i=2;i<=*n;i++){
		for(j=1;j<i;j++){
			if(*(num+i)<=*(num+j)){
				temp=*(num+i);
				move(num,&j,&i);
				*(num+j)=temp;
				break;
			}
		}
		trace(num,*n);
	}
}

int main(){
  int n, i, j;
  int A[1001];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
  trace(A, n);
  change(A,&n);

  return 0;
}
