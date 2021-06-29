#include<stdio.h>

int search(int s[], int n, int key)
{
   int i = 0;
   s[n] = key;
   while(s[i] != key){
      i++;
   }

   return i != n;
}

int main()
{
   int n, q, i;
   int key = 0;
   int count = 0;
   int s[10000];

   scanf("%d\n", &n);

   for(i = 0; i < n; i++){
      scanf("%d", &s[i]);
   }

   scanf("%d\n", &q);

   for(i = 0; i < q; i++){
      scanf("%d", &key);
      if(search(s, n, key)){
         count++;
      }
   }

   printf("%d\n", count);

   return 0;
}
