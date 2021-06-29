#include <stdio.h>
main(){
  int i, j, m, N;
  int r[100];
  scanf("%d",&N);
  for(i=0;i< N;i++)
    scanf("%d",&r[i]);
  for(i=1;i<=N;i++){
    for(j=0;j<N-1;j++)
      printf("%d ",r[j]);
    printf("%d\n",r[j]);
    m=r[i];
    j=i-1;
    while(j>=0&&r[j]>m){
      r[j+1]=r[j];
      j--;
    }
    r[j+1]=m;
  }
  return 0;
}
