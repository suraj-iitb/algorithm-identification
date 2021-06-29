#include<stdio.h>
int main(){
  int num,i=0,j=0,k=0,key;
  scanf("%d",&num);
  int stuck[num];
  for(i=0;i<num;i++){
    scanf("%d",&stuck[i]);
  }
  for(k=0;k<num;k++){
    if(k==num-1) printf("%d\n",stuck[k]);
    else  printf("%d ",stuck[k]);
  }
  for(i=1;i<num;i++){
    key=stuck[i];
    j=i-1;
    while(j>=0 && stuck[j]>key){
      stuck[j+1]=stuck[j];
      j--;
    }
    stuck[j+1]=key;
    for(k=0;k<num;k++){
      if(k==num-1)printf("%d\n",stuck[k]);
      else printf("%d ",stuck[k]);
    } 
  }

  return 0;
}

