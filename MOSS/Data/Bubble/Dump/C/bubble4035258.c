#include<stdio.h>

#include<stdlib.h>


int bubblesort (int * ,int);
int main(){
  int i, n,*a,q,f=0;
  scanf(" %d",&n);

  a=(int *)malloc(n *sizeof(int));
  for(i=0;i<n;i++){

    scanf(" %d",&a[i]);
   
  }
 f= bubblesort(a,n);
 //printf("%d",a[0]);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");;
    printf("%d",a[i]);
  }
 printf("\n%d\n",f);

 return 0;
}

int bubblesort(int *A,int N){
  int i,j,k,l,m=0;
  for(i=0;i<N-1;i++){
    for (j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1])
	{
	  k=A[j];
	  l=A[j-1];
	  A[j]=l;
	  A[j-1]=k;
	  m++;
	}
    }
  }
  
  return m;
}

