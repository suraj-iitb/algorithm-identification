#include<stdio.h>

int linerSearch(int[],int,int);

  int main(){

    int i,h,H[10000+1], q, key, sum = 0;
    
    scanf("%d",&h);
  
  for( i = 0 ; i < h ; i++ ){
    scanf("%d",&H[i]);
  }

  scanf("%d",&q);
  
  for( i = 0 ; i < q ; i++ ){
    
    scanf("%d",&key);
    
    if( linerSearch(H, h , key))sum++;
  }
  printf("%d\n",sum);

  return 0;
}
 
    
int linerSearch(int H[],int h,int key){
  int i = 0;
  H[h] = key;
  while( H[i] != key )i++;
  return i != h;
}

