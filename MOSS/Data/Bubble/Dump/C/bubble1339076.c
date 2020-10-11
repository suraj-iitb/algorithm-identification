#include <stdio.h>
int main(){
  int N, i, j, k, ch = 0;
  int _N[100];
  scanf("%d",&N);
  for( i = 0 ; i < N ; i++)
    scanf("%d",&_N[i]);
  for(i = 0 ; i < N ; i++){
    for(j = N - 1 ; j >= i+1 ; j--){
      if(_N[j] < _N[j-1]){
    k = _N[j];
    _N[j] = _N[j-1];
    _N[j-1] = k;
    ch++;
      }
    }
  }
  for(i = 0 ; i < N-1 ; i++)
    printf("%d ",_N[i]);
  printf("%d\n",_N[i]);
  printf("%d\n",ch);
   return 0;
}
