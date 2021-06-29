#include <stdio.h>

int main(void){

  int size=0,exch=0;
  scanf("%d",&size);
  int seq[size];
  for(int i=0;i<size;i++){
    scanf("%d",&seq[i]);
    //正解のため
    if(i==size-1){
      printf("%d\n",seq[i]);
      break;
    }
    printf("%d ",seq[i]);
  }
  for(int i=1;i<size;i++){
    for(int j=i;j>0;j--){
      if(seq[j-1]<seq[j]){
        break;
      }
      exch=seq[j-1];
      seq[j-1]=seq[j];
      seq[j]=exch;
    }
    //途中経過
    for(int k=0;k<size-1;k++){
      printf("%d ",seq[k]);
    }printf("%d\n",seq[size-1]);
  }


  return 0;
}

