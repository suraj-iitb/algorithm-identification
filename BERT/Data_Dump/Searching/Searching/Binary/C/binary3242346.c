#include <stdio.h>

int main(void)
{
 int n, q, i, left, right, mid;
 int a[100000];
 int b[50000];
 int k = 0;
 
 scanf("%d", &n);
 
 for(i = 0; i < n; i++)
  scanf("%d", &a[i]);

 scanf("%d", &q);

 for(i = 0; i < q; i++)
  scanf("%d", &b[i]);

 right = n;
 left = 0;

for(i = 0; i < q; i++) 
{
 while(left < right)
 {
  mid = (left + right) / 2;

   if(a[mid] == b[i])
{
    k++;
    break;
}
   else if(a[mid] > b[i])
{
    right = mid;
}
   else
{
    left = mid + 1;
}

 }

 right = n;
 left = 0;

}



 printf("%d\n", k);


 return 0;

}


 
 
