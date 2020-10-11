#include <stdio.h>
#define MAX 500000

void divi(int*,int,int);
void conq(int*,int,int,int);
int youko1,haire1[MAX],count=0;
int main()
{
  int i,lefhasi,righasi;
  scanf("%d",&youko1);
  for(i=0;i<youko1;i++)
    {
      scanf("%d",&haire1[i]);
    }
  lefhasi=0;
  righasi=youko1;
  divi(haire1,lefhasi,righasi);
  for(i=0;i<youko1-1;i++)
    {
      printf("%d ",haire1[i]);
    }
  printf("%d\n",haire1[youko1-1]);
  printf("%d\n",count);
  return 0;
}

void divi(int *haire1,int lefhasi,int righasi)
{
  int man;
  if(lefhasi+1<righasi)
    {
      man=(lefhasi+righasi)/2;
      divi(haire1,lefhasi,man);
      divi(haire1,man,righasi);
      conq(haire1,lefhasi,man,righasi);
    }
}

void conq(int *haire1,int lefhasi,int man,int righasi)
{
  int lefnum,rignum,i=0,j=0,k=0;
  lefnum=man-lefhasi;
  rignum=righasi-man;
  int lefhai[lefnum+1],righai[rignum+1];
  for(i=0;i<lefnum;i++)
    {
      lefhai[i]=haire1[lefhasi+i];
      // printf("%d\n",lefhai[lehasi+i]);
    }
  for(i=0;i<rignum;i++)
    {
      righai[i]=haire1[man+i];
      //printf("%d\n",righai[man+i]);
    }
  lefhai[lefnum]=1000000000;
  righai[rignum]=1000000000;
  i=0;
  for(k=lefhasi;k<righasi;k++)
    {
      if(lefhai[i]<=righai[j])
	{
	  haire1[k]=lefhai[i];
	  i++;
	  count++;
	}
      else
	{
	  haire1[k]=righai[j];
	  j++;
	  count++;
	}
    }
}
//4124232
/*

int divi(int haire1[],int lehasi,int rihasi)
{
  int man;
  if(lehasi+1<rihasi)
    {
      man=(lehasi+rihasi)/2;
      divi(haire1[],lehasi,man);
      divi(haire1[],man,rihasi);
      conq(haire1[],lehasi,man,rihasi);
    }
  return 0;
}

int conq(int haire1[],int lehasi,int man,int rihasi)
{
  int lefnum,rignum,lefhai,righai,i=0,j=0,k=0;
  lefnum=man-lehasi;
  rignum=right-man;
  for(i=1;i<=lefnum-1;i++)
    {
      lefhai[i]=haire1[lehasi+i];
      printf("lefhai[lehasi+i]\n");
    }
  for(i=1;i<=rignum-1;i++)
    {
      righai[i]=haire1[man+i];
      printf("righai[man+i]\n");
    }
  lefhai[lefnum]=50000;
  righai[rignum]=50000;
  i=0;
  for(k=lehasi;k<rihasi;k++)
    {
      if(lefhai[i]<=righai[j])
	{
	  haire1[k]=lefhai[i];
	  i++;
	  count++;
	}
      else
	{
	  haire1[k]=righai[j];
	  j++;
	  count++;
	}
    }
  return 0;
}
  int man,haileft[100],hairight[100],p,q;
  //printf("%d\n",lehasi);
  //printf("%d\n",rihasi);
  if(lehasi+1<rihasi)
    {
      man=(lehasi+rihasi)/2;
      //printf("%d\n",man);
      for(p=lehasi;p<=man;p++)
	{
	  printf("%d ",haire1[p]);
	}
      printf("\n");
      for(q=man+1;q<rihasi;q++)
	{
	  printf("%d ",haire1[q]);
	}
      printf("\n");
      divi(lehasi,man);
      divi(man,rihasi);
      conq(lehasi,man,rihasi);
    }
  return 0;
}
 */

