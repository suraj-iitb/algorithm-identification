#include <stdio.h>
#define MAXn 100000
#define MAXq 50000

int main(){
  int sn, tqn, Snum[MAXn], Tq[MAXq], i, left, right, mid, key, cnt=0;
  
  scanf("%d", &sn);
  for(i=0;i<sn;i++){
    scanf("%d", &Snum[i]);
  }
  scanf("%d", &tqn);
  for(i=0;i<tqn;i++){
    scanf("%d", &Tq[i]);
  }

  for(i=0;i<tqn;i++){
    key = Tq[i];
    left = 0;
    right = sn;
    while(left < right){
      mid = (left+right)/2;
      if(Snum[mid] == key){
        cnt++;
        break;
      }
      else if(key < Snum[mid]){
        right = mid;
      }
      else{
        left = mid+1;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
