#include<stdio.h>

int H[1000000],h;
int binarySearch(int);

int main(){
  
  int i,q,a,sum=0;

  scanf("%d",&h);
  
  for(i=0;i<h;i++){
    
    scanf("%d",&H[i]);
    
  }

  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    
    scanf("%d",&a);
    
    if(binarySearch(a))sum++;
      
    
  }
  
  printf("%d\n",sum);
  
  return 0;
  
}

int binarySearch(int key){
  
  int left = 0;
  
  int right = h;
  
  int mid;
  
  while(left < right){
    
    mid = (left + right)/2;
    
    if(key == H[mid])return 1;
    
    if( key > H[mid])left= mid + 1;
    
    else if(key < H[mid])right = mid;

  }
  
  return 0;
  
}


    
  

