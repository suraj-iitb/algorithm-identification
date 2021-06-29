#include <stdio.h>
#define A 100
int main(void){
  int num,i,j,in[A],temp,min;
  int cnt = 0;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&in[i]);
  }
 
  for(i=0;i<num;i++){
    min = i;
    for(j=i;j<num;j++){
      if(in[j]<in[min]) min = j;
    }
    //if(min != i){
    if(in[i]>in[min]){
    temp = in[i];
    in[i] = in[min];
    in[min] = temp;
    cnt++;
  }
}

  for(i=0;i<num-1;i++){
    printf("%d ",in[i]);
  }
  
    printf("%d\n%d\n",in[num-1],cnt);

  return 0;
}

