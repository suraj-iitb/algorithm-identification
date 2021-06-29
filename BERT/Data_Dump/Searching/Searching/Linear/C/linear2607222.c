#include<stdio.h>
 
int main()
{
  int n, S[10000], q, T[500], C, i, j, flag;
  C = 0;
 
  scanf("%d", &n);

  for(i = 0;i < n;i++) scanf("%d", &S[i]);

  scanf("%d", &q);

  for(i = 0;i < q;i++) scanf("%d", &T[i]);

  for(i = 0;i < q;i++){
    flag = 0;
    for(j = 0;j < n && flag == 0;j++){
      if(S[j] == T[i]){
        C++;
        flag = 1;
      }
    }
  }
 
  printf("%d\n", C);
 
  return 0;
}
