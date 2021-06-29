#include <stdio.h>

#define N 100

int main(){
  int i,j,count,Arr[N],key;
  scanf("%d",&count);

  for(i=0;i<count;i++){
    scanf("%d",&Arr[i]);
  }
  
  for(i=0;j<count-1;j++){
    printf("%d ",Arr[j]);
  }
  printf("%d\n",Arr[count-1]);

  for(i=1;i<count;i++){
    key = Arr[i];
    j = i-1;
    while(j>=0 && Arr[j]>key){
      Arr[j+1]=Arr[j];
      j--;
      Arr[j+1]=key;
    }

    for(j=0;j<count-1;j++){
      printf("%d ",Arr[j]);
    }
    printf("%d\n",Arr[count-1]);
  }
  return 0;
}
    


  

