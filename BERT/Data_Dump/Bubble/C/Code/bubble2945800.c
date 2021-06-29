#include<stdio.h>
int main(){
  int N,i,a[100],count,tmp,flag;
  flag = 1;
  count = 0;
  scanf("%d",&N);
  for(i = 0;i < N;i++) scanf("%d",&a[i]);
  while(flag){
    flag = 0;
    for(i = N-1;i > 0; i--){
      if(a[i] < a[i-1]) {
        tmp = a[i];
        a[i] = a[i-1];
        a[i-1] = tmp;
        count++;
        flag = 1;
      }
    }
  }
  for(i = 0;i < N; i++){
     printf("%d",a[i]);
     if(i != N-1) printf(" ");
   }
  printf("\n%d\n",count);
  return 0;
}

