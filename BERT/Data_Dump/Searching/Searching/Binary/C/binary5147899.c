#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 100
int main()
{
  int i = 0, j = 0, num, num1, num2, num3, num4, cnt = 0;;

  scanf("%d", &num);

  int H[num];

  while(i < num){
    scanf("%d", &H[i]);
    i++;
  }

  scanf("%d", &num1);

  int I[num1];

  while(j < num1){
    scanf("%d", &I[j]);
    num2 = num;
    num3 = 0;
    while(num3 < num2){
      num4 = (num3 + num2) / 2;
      if(I[j] == H[num4]){
        cnt++;
        break;
      }
      if(I[j] > H[num4]) num3 = num4 + 1;
      else if (I[j] < H[num4]) num2 = num4;
    }
    j++;
  }
  printf("%d\n", cnt);
  return 0;
  }

