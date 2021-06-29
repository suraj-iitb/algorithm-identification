#include<stdio.h>
#define N 100


void selectionsort(int A[], int n, int *c){
  int i,j,s,minj=0;

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj])
	minj = j;
    }
    if(A[i]!=A[minj])
      (*c)++;
    s=A[i];
    A[i]=A[minj];
    A[minj]=s;
  }
}




int main(){

  int A[N],n,i,c=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  selectionsort(A,n,&c);

  for(i=0;i<n;i++){
    if((i+1)==n)
      printf("%d",A[i]);
    else
      printf("%d ",A[i]);
  }
  putchar('\n');
  printf("%d",c);
  putchar('\n');
  return 0;

}

