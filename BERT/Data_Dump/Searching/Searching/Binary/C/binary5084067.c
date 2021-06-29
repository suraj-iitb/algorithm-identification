#include<stdio.h>
#include<stdlib.h>

int binarySerch(int , int );
int *S, *T;

int main(){
  int n, q, i, key, cnt = 0;

  scanf("%d",&n);
  S = malloc(sizeof(int) * n);

  for(i=0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  T = malloc(sizeof(int) * q);

   for(i=0; i < q; i++){
    scanf("%d",&T[i]);
  }

   for(i = 0; i < q; i++){
     key =T[i];
     if((binarySerch(key, n)) != 0)cnt++;
   }

   printf("%d\n",cnt);

   return 0;
}

int binarySerch(int key, int n){
  int left = 0, right = n, mid;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key) return mid;
    else if(key < S[mid]) right = mid;
    else left = mid +1 ;
  }
  return 0;
}

