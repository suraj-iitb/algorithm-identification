#include<stdio.h>
#define N 100


void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}



int main(){
  int n,i,j,k=0,kaunt=0,minj;//k=hozon
  int A[N];

  scanf("%d",&n);
  for(i =0;i<n;i++)scanf("%d",&A[i]);


  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj])minj=j;
    }
    k=A[i];
    A[i]=A[minj];
    A[minj]=k;
    kaunt++;
    if(minj==i)kaunt--;
  }

  

  trace(A,n);
  printf("%d\n",kaunt);
  
  return 0;
}
