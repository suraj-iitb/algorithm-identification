#include <stdio.h>

int main()
{
 int i, n, m, t, ans=0;
 int a[10000];
 scanf("%d", &n);

 for(i=0; i<n; i++){
  scanf("%d", a+i);
 }

 scanf("%d", &m);

 while(m-- > 0){
  scanf("%d", &t);
  for(i=0; i<n; i++){
   if(a[i] == t){
    ans++;
    break;
   }
  }
 }

 printf("%d\n", ans);
 return 0;
}
