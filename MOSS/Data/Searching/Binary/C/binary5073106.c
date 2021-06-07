#include<stdio.h>

int binarysearch(int,int,int*);

int main()
{
  int i,left,right,mid;
  int  count = 0;
  int n;
  int s[100000];
  int q;
  int t[50000];

  scanf("%d",&n);
 
  for(i = 0; i < n; i++)scanf("%d",&s[i]);

  scanf("%d",&q);
 
    for(i = 0; i < q; i++)scanf("%d",&t[i]);


    for(i = 0; i < q; i++)
      {
	count = count + binarysearch(n,t[i],s);
      }
    printf("%d\n",count);/*    for(i = 0; i < q; i++)
      {
	left = 0;
	right = n;
	mid = 0;

	
	while(left < right)
	  {
	    mid = (left + right)/2;
	    if(t[i] == s[mid]) return  1;
	    if(t[i] > s[mid])left = mid + 1;
	    else if(t[i] < s[mid])right = mid;
	  }
      }
    printf("%d\n",count);
    */
    return 0;
}

int binarysearch(int n,int t,int *s)
{
  int left = 0,right = n,mid = 0;
        
  while(left < right)
    {
      mid = (left + right)/2;
     
      if(t == s[mid])return 1;
      if(t > s[mid])left = mid + 1;
      else if(t < s[mid])right = mid;
    }
  return 0;
}
	    
	    

    
    

