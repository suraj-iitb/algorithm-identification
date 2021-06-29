#include<stdio.h>
#define N 100
int main(){

  int min,temp,i,j,count=0,x[N],n;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&x[i]);

  for(i=0;i<n;i++){
    min = i;

    for(j=i;j<n;j++){
      if( x[j] < x[min] ) min = j;
    }

    if( x[i] != x[min] ){
      temp = x[i];
      x[i] = x[min];
      x[min] = temp;
      count++;
    }
  }

  for(i=0;i<n-1;i++) printf("%d ",x[i]);
  printf("%d\n",x[n-1]);
  printf("%d\n",count);
  return 0;
}
