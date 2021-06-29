#include<stdio.h>
#define N 100

int main(){
  int i,j,n,cnt=0,tmp;
  int A[N],mini;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
    if(i!=mini){
      tmp=A[i];
      A[i]=A[mini];
      A[mini]=tmp;
      cnt++;
    }
    
  }
  
  
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",cnt);

  return 0;
}
