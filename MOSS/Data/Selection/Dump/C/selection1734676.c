#include <stdio.h>
#define N 100
int main(){
  int n,i,j,count=0;
  int A[N];
  int minj;
  int temp;
  scanf("%d",&n);
  for(i=0;i<n;i++){  
scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){    
   minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
        }
    }
    if(A[i]!=A[minj]){
   	temp=A[minj];
       A[minj]=A[i];
       A[i]=temp;
       count++;
    }
  }
 for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);

  return 0;
}
