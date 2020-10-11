#include<stdio.h>
 
int main(){
  int N,a[100],flag=1,i,j,tmp,n=0;
 
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
 
  i =0;
  while(flag){
    flag =0;
    for(j = N-1;j > i;j--){
      if(a[j] < a[j-1]){
    tmp = a[j];
    a[j] = a[j-1];
    a[j-1] = tmp;
    flag = 1;
    n++;
      }
    }
    i++;
  }
  for(i = 0;i<N-1;i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[N-1],n);
 
  return 0;
}
