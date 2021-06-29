#include <stdio.h>
main()
{
  int A[1000];
  int i,j;
  int num,ans,temp=0;
  int hant_num=0; /*反転回数*/

  scanf("%d",&num);
  for(i=0;i<num;i++)
    {
      ans = scanf("%d",&A[i]);
    }
  for(i=0;i<num;i++)
    {
      for(j=num-1;j>=i+1;j--)
	{
	  if (A[j-1] > A[j]) 
	    {
	      temp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = temp;
	      hant_num++;
	    }
	}
    }
  for (i=0;i<num;i++)
    {
      printf("%d",A[i]);
      if (i<num-1)printf(" ");
      else printf("\n");
    }
  printf("%d\n",hant_num);
  return 0;
}
