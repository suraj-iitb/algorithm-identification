#include<stdio.h>

int main(){
  int S[100000],T[100000],c,b,i,j,mid,count=0;
  double left,right;
  
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&c);
  for(i=0;i<c;i++){
    scanf("%d",&T[i]);
  }

  
  
 
  for(i=0;i<c;i++){
    right=b;
    left=0;

    
    while(left<=right){
      mid=(left+right)/2;
      
      if(S[mid]==T[i]){
        count++;
        break;
      }
     else if (T[i] > S[mid]) {
      left = mid+1; 
    } else {
      right = mid-1; 
     }
  }
  }

  
  printf("%d\n",count);

  

  return 0;
}

