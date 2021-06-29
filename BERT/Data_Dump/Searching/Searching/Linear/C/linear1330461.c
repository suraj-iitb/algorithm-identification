#include<stdio.h>
#define SM 10000
#define TM 500
main()
{

  int i;
  int j;
  int c = 0;
  int q;
  int n;
  int s[SM];
  int t[TM];

  scanf("%d",&n);

  for(i = 0;i < n;i++)
    {
      scanf("%d",&s[i]);
    }


  scanf("%d",&q);

  for(i = 0;i < q;i++)
    {
      scanf("%d",&t[i]);
    }


  for(i = 0;i < q;i++)
    { 
      for(j = 0;j < n;j++)
	{
	  if(t[i] == s[j])
	    {
	      c++;
	      break;
	    }
	}
    }

  printf("%d\n",c);

  return 0;
}
