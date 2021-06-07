#include <stdio.h>
#define N 1000000
#define Q 50000
main(){
  int s[N], t[Q];
  int i, j, right, left, center, a, b, count = 0;
  scanf("%d", &a);
  for(i=0;i<a;i++)
    {
      scanf("%d", &s[i]);
    }
  scanf("%d", &b);
  for(j=0;j<b;j++)
    {
    scanf("%d", &t[j]);
    left = 0;
    right = a;
    while(left <= right)
     {
      center = (left + right) / 2;
      if(t[j] == s[center])
       {
	count += 1;
        break;
       }
      else if(t[j] > s[center])
        left = center + 1;
      else if(t[j] < s[center])
        right = center - 1;
     }
   }
   printf("%d\n", count);
   return 0;
    }
    
