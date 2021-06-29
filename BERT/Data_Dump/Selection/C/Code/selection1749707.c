#include<stdio.h>
int main(){
  
  int N,a[100],i,j,counter=0,alternative,minj;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    alternative=a[i];
    a[i]=a[minj];
    a[minj]=alternative;
    if(i!=minj){
      counter=counter+1;
    }
  }
  
  for(i=0;i<N-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[N-1]);
  printf("%d\n",counter);

  return 0;
}
