#include<stdio.h>
#include<stdlib.h>
#define MAX 200000

int main()
{
  int i = 0, j = 0, num, s, t = 0, S[MAX];
  scanf("%d", &num);
  while(i < 10000){
    S[i] = 0;
    i++;
  }
  for(i = 0; i < 10; i++){
    printf("");
  }
  while(j < num){
    scanf("%d", &s);
    S[s]++;
    j++;
  }
  i = j = 0;
  while(i < 10000){
    for(j = 0; j < S[i]; j++){
      if(t == 0){
        printf("%d", i);
        t+=1;
      }
      else{
        printf(" %d", i);
      }
    }
    i++;
  }
  printf("\n");
  return 0;
}

