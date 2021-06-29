#include <stdio.h>
int main(){
  int i,j,a,b,hai1[100000],hai2[50000],c1=0,c2=0,left,right,mid;
  scanf("%d",&a);
  for(i=0;i < a ; i++){
    scanf("%d",&hai1[i]);
  }
  scanf("%d",&b);
  for(i=0;i < b ; i++){
    scanf("%d",&hai2[i]);
  }
 
 
  for(i=0;i < b ; i++){
    left=0;
    right=a;
    while(left <= right){
      mid=(right+left)/2;
      if(hai1[mid]==hai2[i]){
        c1++;
        c2++;
        break;
        if(c2 >=2){
          c1--;
        }
      }
      if(hai1[mid] < hai2[i]){
        left=mid+1;
      }
      else if(hai1[mid] > hai2[i]){
        right=mid-1;
      }
    
    }
   
  }
  printf("%d\n",c1);
  return 0;
}


