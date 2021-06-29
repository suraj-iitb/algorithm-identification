#include <stdio.h>
int binSearch(int);
 
int S[100000];
int n;
int main(){
  int i;
  int T[50000],q,C=0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }
 
  for(i = 0; i < q; i++){
    if(binSearch(T[i])) C++;
  }
  printf("%d\n",C);
  return 0;
}
 
int binSearch(int key){
  int left = 0;
  int right = n;
  int mid;
  while( left < right){
    mid = (left + right) / 2;
    if(S[mid] == key) return 1;
    else if(key < S[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}
