#include<stdio.h>
int main(){
  int N,i,j,k,v;
  int a[100];
  scanf("%d",&N);
  for(i = 0;i < N; i++){
    scanf("%d",&a[i]);
  }
  for(i = 1;i <= N-1; i++){
    for(k = 0;k < N; k++){
      printf("%d",a[k]);
      if(k != N-1)
	printf(" ");
    }
    printf("\n");
    v = a[i];
    j = i-1;
    while(j >= 0&&a[j]>v){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    
  }
  
  for(k = 0;k < N; k++){
    printf("%d",a[k]);
    if(k != N-1)
	printf(" ");
  }
  printf("\n");
}
