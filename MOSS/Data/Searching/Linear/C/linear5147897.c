#include<stdio.h>

int main()
{
  int num, q, i = 0, j = 0, cnt = 0;

  scanf("%d", &num);
  int S[num];

  while(i < num){
    scanf("%d", &S[i]);
    i++;
  }

  scanf("%d", &q);
  int T[q];

  while(j < q){
    scanf("%d", &T[j]);
    j++;
  }
  /*  for(i = 0; i < num; i++){                                                                    
    printf("%d", S[i]);                                                                            
  }                                                                                                
  for(j = 0; j < q; j++){                                                                          
    printf("%d", T[j]);                                                                            
    }*/

  for(j = 0; j < q; j++){
    for(i = 0; i < num; i++){
      if(S[i] == T[j]){
        cnt++;
        break;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}


