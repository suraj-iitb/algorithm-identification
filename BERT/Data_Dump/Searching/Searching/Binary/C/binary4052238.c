//2019.12.16
//s1270188 momoka murakami
//alds1_04b Binary Search

#include<stdio.h>
#include<stdlib.h>

int main(){
  int *data, num;
  int s_num, cnt=0, search, left, mid, right;
  int i;


  //input
  scanf("%d",&num);
  data=(int *)malloc(sizeof(int)*num);
  for(i=0;i<num;i++) scanf("%d",&data[i]);


  //search
  scanf("%d",&s_num);
  for(i=0;i<s_num;i++){
    scanf("%d",&search);
    
    left=0;
    right=num;
    while(left<right){
      mid=(left+right)/2;

      if(search==data[mid]){
	cnt++;
	break;
      }
      
      if(search>data[mid]) left=mid+1;
      else right=mid;
    }

    
  }
  

  
  //output cnt
  printf("%d\n",cnt);
  

  free(data);
  return 0;
}

