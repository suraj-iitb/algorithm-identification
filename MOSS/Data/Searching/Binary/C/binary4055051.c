#include <stdio.h>

int nm=0;
void binarysearch(int *, int, int);

int main(){
  int snm, tnm, i;
  int S[100000], T[50000];
  
  scanf("%d", &snm);
  for(i=0; i<snm; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &tnm);
  for(i=0; i<tnm; i++){
    scanf("%d", &T[i]);
  }
  
  for(i=0; i<tnm; i++){
  binarysearch(S, T[i], snm);
  }
  printf("%d\n", nm);
  
  return 0;
}
void binarysearch(int *S, int T, int snm){
  int left=0, right=snm, mid;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == T){
      nm++;
      break;
    }
    else if(T < S[mid]) right = mid;
    else left = mid + 1;
  }
}
