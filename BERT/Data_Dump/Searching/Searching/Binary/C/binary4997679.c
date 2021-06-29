#include<stdio.h>

int array[1000000];
int n;

int binarySearch(int key){
  int left = 0;
  int right = n;
  while(left < right){
    int mid=(left+right)/2;
    if(key==array[mid]) return 1;
    if(key>array[mid])left = mid+1;
    else if(key<array[mid]) right = mid;
  }
  return 0;
}

int main(){
  int i,j,q;
  int count = 0;
  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    scanf("%d",&array[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&j);
    
    if(binarySearch(j)){
	count++;
	}
  }
  printf("%d\n",count);
  return 0;
}

