#include<stdio.h>
int main(){
  int i,j,k;
  int n;
  int N;
  int hako[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&hako[i]);
  }
  for(k=0;k<N-1;k++){
    printf("%d ",hako[k]);
  }
  printf("%d",hako[N-1]);
  printf("\n");

  for(i=1;i<N;i++){
    n = hako[i];
    j = i-1;
    while(j >=0 && hako[j]>n){
      hako[j+1] = hako[j];
      j--;
    }
    hako[j+1]=n;

   
    for(k=0;k<N-1;k++){
      printf("%d ",hako[k]);
    }
    printf("%d",hako[N-1]);
    printf("\n");
  }
  return 0;
}

