#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,*num,i,j,t,cnt=0;
  scanf("%d",&n);
  num = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&num[i]);
  
  for(i = 0; i < n-1 ; i++){
    for(j = n-1; j > i ; j --){
      if(num[j-1] > num[j]){
        t = num[j];num[j] = num[j-1];num[j-1] = t;
        cnt++;
       }
    }
  }
  for(i=0;i<n;i++){
    if(i == n-1){
      printf("%d",num[i]);
      break;
     }
     printf("%d ",num[i]);
  }
  /*
    i=0;
  while(i<n){
    if(i == n-1) printf("%d\n",num[i]);break;
    printf("%d",num[i]);
      i++;
      printf(" ");
  }
  */
 
  printf("\n%d\n",cnt);
  return 0;
}

