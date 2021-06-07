#include<stdio.h>
int linearsearch(int t, int S[], int ns)
{
	int i;
	int tf = 0;
   for (i = 0; i < ns; ++i) {
      if (S[i] == t) {
         tf = 1;  break;
	   }
   }
   return tf;
}

int main()
{
   int ns, nt;
   int S[16384], T[512];
   int i = 0,
	   count = 0;
   int flag;

   scanf("%d", &ns);
   while (i < ns) {
      scanf("%d", &S[i]);
      i++;
   }
   i = 0;
   scanf("%d", &nt);
   while (i < nt) {
	   scanf("%d", &T[i]);
	   i++;
   }

   for (i = 0; i < nt; ++i) {
      count += linearsearch(T[i], S, ns);
   }

   printf("%d\n", count);
   return 0;
}
