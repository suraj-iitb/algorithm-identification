#include<stdio.h>
#define N 100


int bubblesort(int A[], int n,int *c){
  int i,j,s;

  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	s=A[j];
	A[j]=A[j-1];
	A[j-1]=s;
	(*c)++;
	
      }
    }
   
  }
}




int main(){

  int A[N],n,i,c=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  bubblesort(A,n,&c);

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

