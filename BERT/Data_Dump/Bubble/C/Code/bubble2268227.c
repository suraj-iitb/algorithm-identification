#include <stdio.h>
int main()
{
  int i, j, k, num[100], tmp, x=0;
  
  scanf("%d", &k);
  for(i=0; i < k; i++)
    {
    scanf("%d", &num[i]);
  }
  
  for(i=0; i<k-1; i++)
    {
    for(j = k-1; j>i; j--)
      {
	if(num[j-1]>num[j])
	  {
	tmp = num[j-1];
	num[j-1] = num[j];
	num[j] = tmp;
	x++;
      }
    }
  }
  
  for(i=0; i<k; ++i)
    {
  printf("%d", num[i]);
  if(i+1>=k) break;
  printf(" ");
  }
  printf("\n%d\n", x);
  
  return 0;
}
