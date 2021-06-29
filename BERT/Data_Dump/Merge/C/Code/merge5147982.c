#include<stdio.h>
#include<stdlib.h>
#define MAX 500000

int S[MAX], T[MAX], cnt = 0;

void sortm(int *, int, int);

int main()
{
  int q, num, i = 0, j = 0;
  for(q = 0; q < 10; q++){
    printf("");
    if(q == 11)break;
  }
  scanf("%d", &num);
  while(i < num){
    scanf("%d", &S[i]);
    i++;
  }
  sortm(S, 0, num - 1);
  while(j < num - 1){
    printf("%d ", S[j]);
    j++;
  }
  printf("%d\n%d\n", S[num - 1], cnt);
  return 0;
}void sortm(int *S, int y, int z)
{
  int s = 0, t = 0, c = 0, num1 = 0, num2;
  while(num1 < 1000){
    T[num1] = num1;
    num1++;
  }
  if(z > y){
    num2 = (z + y) / 2;
    sortm(S, y, num2);
    sortm(S, num2 + 1, z);
    s = num2 + 1;
    while(s > y){
      T[s - 1] = S[s - 1];
      s--;
    }
    t = num2;
    while(t < z){
      T[z + num2 - t] = S[t + 1];
      t++;
    }
    c = y;
    while(c <= z){
      S[c] = (T[s] < T[t])?T[s++]:T[t--];
      cnt++;
      c++;
    }
  }
}


