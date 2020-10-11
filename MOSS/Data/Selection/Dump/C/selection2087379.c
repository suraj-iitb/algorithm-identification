#include<stdio.h>
int main(void){
  int i,j,k;
  int N;
  int a[200];
  int t;
  int minj;
  int count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)  scanf("%d",&a[i]);


  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(a[j]<a[minj]){
        minj=j;
      }
    }
    if(i!=minj){
      t=a[i];
      a[i]=a[minj];
      a[minj]=t;
      count++;
    }

  }
  for(i=0;i<N-1;i++)  printf("%d ",a[i]);
  printf("%d\n",a[N-1]);

  printf("%d\n",count);


  return 0;
}
