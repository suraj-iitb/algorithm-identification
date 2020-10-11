#include <stdio.h>

int main(void)
{

 int n, i, s;
 int a[100];
 int f = 1;
 int c = 0;

 scanf("%d", &n);

 for(i = 0;i < n; i++)
 scanf("%d", &a[i]);

 while(f == 1)
{
 f = 0;
 
 for(i = n - 1; i > 0; i--)
{
 if(a[i] < a[i-1])
{
 s = a[i];
 a[i] = a[i-1];
 a[i-1] = s;
 f = 1;
 c++;
 s = 0;
}


}

 }

 for(i = 0; i < n; i++)
if(i < n - 1)
 printf("%d ", a[i]);
 else
 printf("%d", a[i]);

 printf("\n%d\n", c);

 return 0;

}


