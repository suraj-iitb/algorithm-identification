#include<stdio.h>

int main(){
  int i,j,a[100],N,minj,n=0,tmp;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);

  for(i=0;i<N;i++){
    minj = i;
    for(j = i;j<N;j++){
      if(a[j]<a[minj]){
	minj = j;
      }
    }
    if(i != minj){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      n++;
    }
  }

  for(i=0;i<N-1;i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[N-1],n);

  return 0;
}
