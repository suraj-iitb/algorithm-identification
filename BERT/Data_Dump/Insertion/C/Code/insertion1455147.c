#include<stdio.h>
int main(){

  int i,j,v,N,a[1000];

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  for(i=1;i<=N;i++){ 
    for(j=0;j<N;j++){
      printf("%d",a[j]);
      if(j<N-1){
	printf(" ");
      }
    }
    puts("");
    v=a[i];
    j=i-1;
    while(j >= 0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }
  }
  return 0;
}
