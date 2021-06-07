#include<stdio.h>

int main(){
  
  int i,j,num,num2,count=0,key;
  int NUM[100001],NUM2[50001];
  
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&NUM[i]);
    
  }
  
  scanf("%d",&num2);
  
  for(i=0;i<num2;i++){
    scanf("%d",&key);

    int left=0,right=num,mid;
    while(left<right){
      mid=(left+right)/2;
      if(NUM[mid]==key){
	count++;
	break;
      }
      else if(key<NUM[mid])
	right=mid;
      else left = mid + 1;
    }
  }
  printf("%d\n",count);  
  return 0;
}
