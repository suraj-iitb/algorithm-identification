#include <stdio.h>

int main(){
  int N,a[100],flag,i,j,cnt=0,t;

  scanf("%d",&N);

  for(i=0;i < N;i++){
    scanf("%d",&a[i]);
  }
  flag = 1;
  while(flag){
    flag=0;
    for(j=N-1,i=1;j>i-1;j--){
    if(a[j]<a[j-1]){
      t=a[j-1];
      a[j-1]=a[j];
      a[j]=t;
      cnt+=1;
      flag=1;
    }
  }
  i++;}

  for(i=0;i<N;i++){
    printf("%d",a[i]);
    if(i==N-1){
      printf("\n");
    }
    else printf(" ");
  }
  printf("%d\n",cnt);

  return 0;
}
