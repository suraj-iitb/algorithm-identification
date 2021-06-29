#include<stdio.h>
#define N 100000

typedef struct{
  int count;
  char pict;
  int number;
}a;

int partition(a *,int,int);
void quicksort(a *,int,int);

main(){

  int n,r,p,i,flag=0;
  a A[N];
  char m;

  scanf("%d%c",&n,&m);

  for( i=0 ; i<n ; i++){
    scanf("%c%d%c",&A[i].pict,&A[i].number,&m);
    A[i].count = i;
  }

  r=n-1;
  p=0;

  quicksort(A,p,r);
   
  for( i=0 ; i<n-1 ; i++){
    if( A[i].number == A[i+1].number && A[i].count > A[i+1].count && flag==0){
      printf("Not stable\n");
      flag=1;
    }
    if(flag == 0 && i == n-2) printf("Stable\n");
  }

  for( i=0 ; i<n ; i++){
    printf("%c %d\n",A[i].pict,A[i].number);
  }
  
  return 0;
}

int partition(a *A,int p,int r){

  int x,i,j;
  a n;

    x = A[r].number;
    i = p-1;

    for( j=p ; j<r; j++){
      if(A[j].number <= x){
	i = i+1;
	n=A[i];
	A[i]=A[j];
	A[j]=n;
	
      }
    }
    n=A[i+1];
    A[i+1]=A[r];
    A[r]=n;
   
    return i+1;
}


void quicksort(a *A,int p,int r){

  int q;

  if( p < r ){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
  return ;
}
