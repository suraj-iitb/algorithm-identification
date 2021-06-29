#include <stdio.h>
void swap(int *,int *);

int main(){
  int i,j,n,A[100],c=0,mini;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n-1;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(A[j] < A[mini]){
	mini=j; 
      }
    }
    if(A[mini]<A[i])c++;
    swap(&A[i],&A[mini]);
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

void swap(int *a,int *b){
  int t;
  t=*a;
  *a=*b;
  *b=t;
}
