#include<stdio.h>

#include<stdlib.h>


int selectionsort (int * ,int);
int main(){
  int i, n,*a,q,f=0;
  scanf(" %d",&n);

  a=(int *)malloc(n *sizeof(int));
  for(i=0;i<n;i++){

    scanf(" %d",&a[i]);
   
  }
 f= selectionsort(a,n);
 //printf("%d",a[0]);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");;
    printf("%d",a[i]);
  }
 printf("\n%d\n",f);

 return 0;
}

int selectionsort(int *A,int N){
  int i,j,k,m=0,l;
  int minj;
  for(i=0;i<=N-1;i++){
    minj=i;
    
   
    for (j=i;j<=N-1;j++){
      
      if(A[j]<A[minj])
	{
	  minj=j;}
    }
	  k=A[i];
      
	  l=A[minj];
	  A[i]=l;
	  A[minj]=k;
	  
  
  if(i!=minj) m++;
}
  
  return m;
}

