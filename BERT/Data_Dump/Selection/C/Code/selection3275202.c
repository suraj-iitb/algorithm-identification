#include <stdio.h>

int main()
{
  int N,i,j,minj,flag,tmp,swap_times=0;

  scanf("%d",&N);

  int a[N];

  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    tmp=a[i];
    a[i]=a[minj];
    a[minj]=tmp;
    if(i!=minj)swap_times++;
  }
  
  for(i=0;i<N;i++){
    printf("%d",a[i]);
    if(i!=N-1) printf(" ");
  }

  printf("\n%d\n",swap_times);

  return 0;
}

