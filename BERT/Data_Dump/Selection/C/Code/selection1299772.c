#include <stdio.h>
int main(){
  int i,j,count=0,minj,array[100],n,box;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&array[i]);

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(array[j] < array[minj]) minj =j;
    }
    if(i != minj){
      box = array[i];
      array[i] = array[minj];
      array[minj] = box;
      count++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",array[i]);
    if( i == n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);
  return 0;
}
