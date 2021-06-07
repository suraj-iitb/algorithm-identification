#include <stdio.h>
#include <string.h>
#define MAX 100001
int main()
{
  int youko1,youko2,haire1[MAX],haire2[MAX],i,j,k=1,l=1,samec=0,hida,migi,man,flag=0;
  //char c1,c2;
  scanf("%d",&youko1);
  //printf("%d\n",youko1);
  for(i=1;i<=youko1;i++)
    {
      scanf("%d",&haire1[i]);
      //printf("%d\n",haire1[i]);
      //haire1[i]=atoi(&c1);
    }
  scanf("%d",&youko2);
  for(j=1;j<=youko2;j++)
    {
      scanf("%d",&haire2[j]);
      //printf("%d\n",haire2[i]);
      //haire2[i]=atoi(&c2);
    }
  hida=1;
  migi=youko1+1;
  while(k<=youko2)
    {
      while(hida<migi)
	{
	  man=(hida+migi)/2;
	  if(haire2[k]==haire1[man])
	    {
	      flag=1;
	      break;
	    }
	  if(haire2[k]>haire1[man])
	    {
	      hida=man+1;
	    }
	  else
	    {
	      migi=man;
	    }
	}
      if(flag==1)
	{
	  samec++;
	}
      flag=0;
      hida=1;
      migi=youko1+1;
      k++;
    }
  printf("%d\n",samec);
  return 0;
}

/*
  if(youko1>youko2)
  {
  ooki=youko1;
  }
  else
  {
  ooki=youko2;
  }
  for(k=1;k<=ooki;k++)
  {
  strcmp(haire1[i]);
  }
  while(k<=youko2)
  {
  //printf("100\n");
  while(l<=youko1)
  {
  //printf("100\n");
  // printf("%d %d\n",l,haire2[k]);
  if(haire2[k]==haire1[l])
  {
  //printf("100\n");
  samec++;
  break;
  }
  else
  {
  l++;
  }
  }
  l=1;
  k++;
  }
  printf("%d\n",samec);
*/

