#include <stdio.h>

#define N 100000

int S[N],T[N];

int n,q;

int binarySearch(int);

int main(){

  int i,j,c=0;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }


 for(i=0; i<q; i++){
   
    if(binarySearch(T[i]) == 1) c++;
  }

  printf("%d\n",c);


  return 0;
}

int binarySearch(int key){

  int left=0,right=n;
  int mid;

  while(left < right){
    mid = (left + right)/2;

    if(S[mid] == key) return 1;
    else if(key < S[mid]) right = mid;
    else left = mid +1;
  } 

  return 0;
}
