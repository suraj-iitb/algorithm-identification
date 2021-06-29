#include<stdio.h>

int main(){
  int n,data[100],temp,i,j,k;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
  scanf("%d",&data[i]);
  }
  for(i = 0;i <= n-1;i++){
    temp = data[i];
    j = i - 1;
    while(j >= 0 && data[j] > temp){
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = temp;
    for(k = 0;k < n-1;k++)printf("%d ",data[k]);
    printf("%d",data[k]);
    printf("\n");
  }
  return 0;
}
