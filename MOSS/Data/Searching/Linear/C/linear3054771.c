#include <stdio.h>

int main(void){
  int i , j , key , s_length , t_length ;
  int ans = 0;


  scanf("%d",&s_length);
  int S[s_length];
  for(i = 0 ; i < s_length ; i++){
    scanf("%d ",&S[i]);
  }

  scanf("%d" , &t_length);
  int T[t_length];
  for(i = 0 ; i < t_length ; i++){
    scanf("%d" , &T[i]);
  }

  for(i = 0 ; i < t_length ; i++){
    key = T[i];
    for(j = 0 ; j < s_length ; j++){
      if(key == S[j]){
        ans++;
        break;
      }
    }
  }


  printf("%d\n",ans);

  return 0;
}

