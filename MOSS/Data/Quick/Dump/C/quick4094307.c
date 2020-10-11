#include <stdio.h>
#include <string.h>

#define INFTY 1000000001

typedef struct{
  char egara;
  int kazu;
}card;


int P(card *,int,int);

void QS(card *,int,int);

void MG(card *,int,int,int);

void MS(card *,int,int);

int main()
{
  int n,i,hata=1;
  
  scanf("%d",&n);
  
  card A[n],B[n];

  for(i=0;i<n;i++)
    {
      scanf("%*c%c%d",&A[i].egara,&A[i].kazu);
      B[i]=A[i];
    }

  QS(A,0,n-1);
  MS(B,0,n);

  for(i=0;i<n;i++)
    {
      if(A[i].egara!=B[i].egara)hata=0;
    }

  if(hata==1)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++)printf("%c %d\n",A[i].egara,A[i].kazu);
  
  return 0;
}

int P(card *A,int p,int r)
{
  int x,i,j;
  card koukan;

  x=A[r].kazu;
  i=p-1;
  for(j=p;j<r;j++)
    {
      if(A[j].kazu<=x)
	{
	  i=i+1;
	  koukan=A[i];
	  A[i]=A[j];
	  A[j]=koukan;
	}
    }
  koukan=A[i+1];
  A[i+1]=A[r];
  A[r]=koukan;
  
  return i+1;
}

void QS(card *A,int p,int r)
{
  int q;

  if(p<r)
    {
      q = P(A,p,r);
      QS(A,p,q-1);
      QS(A,q+1,r);
    }
}

void MS(card *A,int L,int R)
{
  int M;
  
  if(L+1<R)
    {
      M=(L+R)/2;
      MS(A,L,M);
      MS(A,M,R);
      MG(A,L,M,R);
    }
}

void MG(card *A,int L,int M,int R)
{
  int n1,n2,i,j,k;

  n1=M-L;
  n2=R-M;

  card l[n1+1],r[n2+1];

  for(i=0;i<n1;i++) l[i]=A[L+i];
  for(i=0;i<n2;i++) r[i]=A[M+i];

  l[n1].kazu=INFTY;
  r[n2].kazu=INFTY;

  i=0;
  j=0;

  for(k=L;k<R;k++)
    {
      if(l[i].kazu<=r[j].kazu)
	{
	  A[k]=l[i];
	  i=i+1;
	}
      else
	{
	  A[k]=r[j];
	  j=j+1;
	}
    }
}

  

