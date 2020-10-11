#include <stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

typedef struct{
  char suit;
  int value;
}card;

card L[MAX/2+2],R[MAX/2+2];

void conq(card A[],int n,int lefhasi,int man,int righasi)
{
  int lefnum,rignum,i=0,j=0,k=0;
  lefnum=man-lefhasi;
  rignum=righasi-man;
  //int lefhai[lefnum+1],righai[rignum+1];
  for(i=0;i<lefnum;i++)
    {
      L[i]=A[lefhasi+i];
      // printf("%d\n",lefhai[lehasi+i]);
    }
  for(i=0;i<rignum;i++)
    {
      R[i]=A[man+i];
      //printf("%d\n",righai[man+i]);
    }
  L[lefnum].value=R[rignum].value=2000000000;
  i=0;
  for(k=lefhasi;k<righasi;k++)
    {
      if(L[i].value<=R[j].value)
	{
	  A[k]=L[i++];
	}
      else
	{
	  A[k]=R[j++];
	}
    }
}

void divi(card A[],int n,int lefhasi,int righasi)
{
  int man;
  if(lefhasi+1<righasi)
    {
      man=(lefhasi+righasi)/2;
      divi(A,n,lefhasi,man);
      divi(A,n,man,righasi);
      conq(A,n,lefhasi,man,righasi);
    }
}
int partition(card A[],int n,int p,int r)
{
  int i=0,j;
  card t,x;
  x=A[r];
  i=p-1;
  for (j=p;j<r;j++)
    {
      if (A[j].value<=x.value)
	{
	  i = i+1;
	  //A[i] と A[j] を交換
	  t=A[i];
	  A[i]=A[j];
	  A[j]=t;
	}
    }
  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
  return i+1;
}

void quicksort(card A[],int n,int p,int r)
{
  int q;
  if(p<r)
    {
      q=partition(A,n,p,r);
      quicksort(A,n,p,q-1);
      quicksort(A,n,q+1,r);
    }
}

int main()
{
  int n,i,v;
  card A[MAX],B[MAX];
  char S[10];
  int stable=1;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%s %d",S,&v);
      A[i].suit=B[i].suit=S[0];
      A[i].value=B[i].value=v;
    }
  divi(A,n,0,n);
  quicksort(B,n,0,n-1);
  for(i=0;i<n;i++)
    {
      if(A[i].suit!=B[i].suit)
	{
	  stable=0;
	}
    }
  if(stable==1)
    {
      printf("Stable\n");
    }
  else
    {
      printf("Not stable\n");
    }
  for(i=0;i<n;i++)
    {
      printf("%c %d\n",B[i].suit,B[i].value);
    }
  return 0;
}

