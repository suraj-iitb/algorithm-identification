#include <stdio.h>
#define S_MAX 100000
#define T_MAX 50000

int main(){
  int ns,nt,i,j,mid,count = 0;
  int s[S_MAX],t[T_MAX];

  scanf("%d" ,&ns);
  for(i = 0; i < ns; i++){
    scanf("%d", &s[i]);
  }

  mid = s[ns/2];

  scanf("%d" ,&nt);
  for(i = 0; i < nt; i++){
    scanf("%d", &t[i]);
  }

  j = 0;
  for(i = 0; i < nt; i++){
    if(t[i] < mid){
      for(j = 0; j < ns; j++){
        if(s[j] == t[i]){
          count++;
          break;
        }
      }
    }else{
      for(j = ns; j >= 0; j--){
        if(s[j] == t[i]){
          count++;
          break;
        }
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
