#include<stdio.h>
int b_search(int t, int S[], int ns)
{
   int i;
   int tf = 0;
   if (S[ns / 2 - 1] == t) {
	  tf = 1;  
   }
   else if (S[ns / 2 - 1] > t) {
	  for (i = 0; i < (ns / 2 - 1); ++i) {
		 if (S[i] == t) {
			tf = 1; break;
		 }
	  }
   }
   else {
	  for (i = ns / 2 - 1; i < ns; ++i) {
		 if (S[i] == t) {
			tf = 1;  break;
		 }
	  }
   }
   return tf;
}

int main()
{
   int ns, nt;
   int S[150000], T[55000];
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
      count += b_search(T[i], S, ns);
   }

   printf("%d\n", count);
   return 0;
}
