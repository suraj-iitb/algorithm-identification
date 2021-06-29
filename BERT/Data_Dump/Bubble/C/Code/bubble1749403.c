#include<stdio.h>

static const int N = 1000;

int main(){
  int n,i,j,flag;
  int A[N+1];
  int swap,sort=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  i=0;
  while(flag){
  flag=0;
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	swap=A[j];
        A[j]=A[j-1];
        A[j-1]=swap;
        flag=1;
        sort++;
      }
     }
    i++;
   }
    for(i=0;i<n;i++){
      if(i<n-1) printf("%d ",A[i]);
      else printf("%d\n",A[i]);
    }
    printf("%d\n",sort);

    return 0;
   } 
