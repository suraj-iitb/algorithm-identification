#include <stdio.h>
#define S_MAX 10000
#define T_MAX 500

int main(){
  int ns,nt,i,j,count = 0;
  int s[S_MAX],t[T_MAX];

  scanf("%d" ,&ns);
  for(i = 0; i < ns; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d" ,&nt);
  for(i = 0; i < nt; i++){
    scanf("%d", &t[i]);
  }

  for(i = 0; i < ns; i++){
    for(j = 0; j < nt; j++){
      if(s[i] == t[j]){
        count++;
        t[j] = -1;
        break;
      }
    }
  }

  printf("%d\n" ,count);

  return 0;
}
