#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,*num,n,j,t,judge;
  int lowkey,lowest,cnt=0,k;
  scanf("%d",&n);
  num = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&num[i]);

  for(i=0;i<n;i++){
    judge = 0;
    lowkey = num[i];
    lowest = i;
    for(j=i+1;j<n;j++){
      if(lowkey > num[j]){
        lowkey = num[j];
        lowest = j;
        judge = 1;
      }
    }
    t = num[i];
    num[i] = num[lowest];
    num[lowest] = t;
    if(judge == 1)cnt++;
  }
 
  for(i=0;i<n;i++){
    if(i == n-1){
      printf("%d\n",num[i]);
      break;
    }
    printf("%d ",num[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
