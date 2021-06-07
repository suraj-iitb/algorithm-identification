#include<stdio.h>
int main(void){
  int a[10000],b[500],count=0;
  int i,j,n,k;
  scanf("%d",&n);
   for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&b[i]);
  }
  for(j=0;j<k;j++){
    for(i=0;i<n;i++){
      if(a[i]==b[j]){
    count++;
    break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
