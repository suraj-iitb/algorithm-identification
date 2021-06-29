#include <stdio.h>

int main(){
  int i,j,minj,count=0,len,array[100],num;

  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&array[i]);
  }
  for(i=0;i<len;i++){
    minj=i;
    for(j=i;j<len;j++){
      if(array[j]<array[minj]) minj=j;
    }
    if(i!=minj){
      num=array[i];
      array[i]=array[minj];
      array[minj]=num;
      count++;
    }
  }
  for(i=0;i<len;i++){
    printf("%d",array[i]);
    if(i==len-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);
  return 0;
}

   

