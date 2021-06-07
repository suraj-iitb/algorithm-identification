#include<stdio.h>

int binarySearch(int *, int);

int n;

int main(void){

  int q,s[100000],t,count=0,i;


  scanf("%d",&n);
  for(i = 0 ; i < n ; i++)
    scanf("%d",&s[i]);


  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&t);

    if(binarySearch(s,t)==1) count++;

  }

  printf("%d\n",count);

  return 0;

}


int binarySearch(int *s, int key){

  int i,left,right,mid;

  left = 0;
  right = n;

  while(left < right){

    mid = (left + right)/2;
      
    if(key == s[mid]) return 1;

    if(key > s[mid]) left = mid + 1;
    else if(key < s[mid]) right = mid;
    
  } 
  
  return 0;

}
