//selectionsort
#include <stdio.h>
void swap(int *,int *);
int main(){
  int i,j,min;
  int A[100];
  int count=0,n;

scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",&A[i]); }

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j]<A[min])min=j;
    }
    if(min!=i){
      swap(&A[i],&A[min]);
      count++;
    }

  }

for(j=0;j<n-1;j++){printf("%d ",A[j]);}
 printf("%d\n%d\n",A[j],count);  

return 0;
}

void swap(int *x, int *y){
  int tmp;
  
  tmp=*x;
  *x=*y;
  *y=tmp;
}

