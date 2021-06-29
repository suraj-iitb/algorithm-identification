#include<stdio.h>
#include<stdlib.h>

int main(){
  int *data, num;
  int s_num, cnt=0;
  int i, j;


  //input
  scanf("%d",&num);
  data=(int *)malloc(sizeof(int)*(num+1));//+1 input search data
  for(i=0;i<num;i++) scanf("%d",&data[i]);


  //search
  scanf("%d",&s_num);
  for(i=0;i<s_num;i++){
    scanf("%d",&data[num]);

    j=0;
    while(data[num]!=data[j]) j++;
    if(j!=num){
      cnt++;
      data[j]=-1;
    }
  }
  

  
  //output cnt
  printf("%d\n",cnt);
  

  free(data);
  return 0;
}

