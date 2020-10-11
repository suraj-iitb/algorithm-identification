#include <stdio.h>

int main(){
  int num,cnt=0,i,tmp,j,minj;
  
  scanf("%d",&num);
  
  int array[num];
  
  for(i=0;i<num;i++)scanf("%d",&array[i]);
  
  for(i=0;i<num;i++){
    minj=i;
    for(j=i;j<num;++j){
      if(array[j]<array[minj]) {
	
	minj = j;
      }
    }

    if(minj != i){
      tmp=array[i];
      array[i]=array[minj];
      array[minj]=tmp;
      cnt++;
    }
  }
  
  for(i=0;i<num-1;i++)printf("%d ",array[i]);
  printf("%d\n%d\n",array[num-1],cnt);
  
  return 0;
  
}


