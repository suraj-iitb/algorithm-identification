#include"stdio.h"
#include"stdlib.h"

typedef struct
{
  char M;
  int N;
}Card;
int partition(Card *A,int p,int r)
{
  int x=A[r].N;
  int i=p-1;
  int j;
  Card buf;
  for(j=p;j<r;j++)
    {
      if(A[j].N<=x)
        {
          i++;
          buf=A[i];
          A[i]=A[j];
          A[j]=buf;
        }
    }
  buf=A[i+1];
  A[i+1]=A[r];
  A[r]=buf;
  return i+1;
}
void quickSort(Card *A,int p,int r)
{
  int q;
  if(p<r)
    {
      q=partition(A,p,r);
      quickSort(A,p,q-1);
      quickSort(A,q+1,r);
    }
}
void Gudge(int n,Card *card,Card *A)
{
  int i,j,f;
  int c=0;
  for(i=1;i<n;i++)
    {
      if(A[i-1].N==A[i].N)
        {
          for(j=c;j<n;j++)
            {
              if(A[i-1].N==card[j].N)
                {
                  if(A[i-1].M==card[j].M)
                    {
                      for(f=j+1;f<n;f++)
                        {
                          if(A[i].N==card[f].N)
                            {
                              if(A[i].M==card[f].M)
                                {
                                  c=j+1;
                                  j=n;
                                  break;
                                }
                              else
                                {
                                  i=n;
                                  j=n;
                                  break;
                                }
                            }
                        }
                    }
                  else
                    {
                      i=n;
                      break;
                    }
                }
            }
        }
      else
        {
          c=0;
        }
    }
  if(i==n+1)
    {
      printf("Not stable\n");
    }
  else
    {
      printf("Stable\n");
    }
}
int main()
{
  int n;
  Card *A;
  Card *B;
  int i;
  int k;
  scanf("%d",&n);
  A=(Card*)malloc(sizeof(Card)*n);
  B=(Card*)malloc(sizeof(Card)*n);
  for(i=0;i<n;i++)
    {
      scanf("%s %d",&A[i].M,&A[i].N);
      B[i].M=A[i].M;
      B[i].N=A[i].N;
    }
  quickSort(A,0,n-1);
  Gudge(n,B,A);
  for(i=0;i<n;i++)
    {
      printf("%c %d\n",A[i].M,A[i].N);
    }
}
