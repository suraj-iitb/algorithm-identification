#include <stdio.h>
#define MAX 100
int main(){

  int key,i,j,n,c;
  int arry[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&arry[i]);
  
  for(i=0;i<n-1;i++)
    printf("%d ",arry[i]);
    printf("%d",arry[n-1]);
  printf("\n");
  
  for(i=1;i<n;i++){
    key=arry[i];
    j=i-1;
    while(j>=0 && arry[j]>key){
      arry[j+1]=arry[j];
      j--;
      arry[j+1]=key;
    }
    for(c=0;c<n-1;c++)
      printf("%d ",arry[c]);
      printf("%d",arry[n-1]);
    printf("\n");
  }
  return 0;
}
