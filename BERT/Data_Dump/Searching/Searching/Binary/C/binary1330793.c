#include<stdio.h>
#define SM 100000
#define TM 50000
main()
{

  int i,n,q,l,m,r,c = 0,han = 0;
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
     l = 0;
     r = n;
     while(1)
       {
	 m = (l + r)/2;
	 if(s[m] == t[i])
	   {
	     c++;
	     break;
	   }
	 else if(l == m || r == m)
	   {
	     break;
	   }

	 else if(s[m] > t[i])
	   {
	     r = m;
	   }
	 else if(s[m] < t[i])
	   {
	     l = m + 1;
	   }
	}
    }


  printf("%d\n",c);

  return 0;
}
