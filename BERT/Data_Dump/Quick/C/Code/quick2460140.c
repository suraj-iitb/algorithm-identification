#include<stdio.h>
#define MAX 100000
#define NUMBER 2000000000

typedef struct
{
  char mark;
  int num;
}cards;

cards c1[MAX/2+2],c2[MAX/2+2];

void merg(cards M[],int n,int left, int middle, int right)
{
  int i,j,l;
  int a,b;
  a=middle-left;
  b=right-middle;
  for(i=0;i<a;i++)c1[i]=M[left+i];
  for(i=0;i<b;i++)c2[i]=M[middle+i];
  c1[a].num=NUMBER;
  c2[b].num=NUMBER;
  i=0;
  j=0;
  for(l=left;l<right;l++)
    {
      if(c1[i].num<=c2[j].num)
        {
          M[l]=c1[i++];
        }
      else
        {
          M[l]=c2[j++];
        }
    }
}

void mergS(cards M[],int n, int left, int right)
{
  int middle;
  if(left+1<right)
    {
      middle=(left+right)/2;
      mergS(M,n,left,middle);
      mergS(M,n,middle,right);
      merg(M,n,left,middle,right);
    }
}int part(cards M[], int n,int posi,int las)
{
  int i,j;
  cards A,B;
  B=M[las];
  i=posi-1;
  for(j=posi;j<las;j++)
    {
      if(M[j].num<=B.num)
        {
          i++;
          A=M[i];
          M[i]=M[j];
          M[j]=A;
        }
    }
  A=M[i+1];
  M[i+1]=M[las];
  M[las]=A;
  return i+1;
}

void quickS(cards M[],int n, int posi,int las)
{
  int k;
  if(posi<las)
    {
      k=part(M,n,posi,las);
      quickS(M,n,posi,k-1);
      quickS(M,n,k+1,las);
    }
}
int main()
{
  int i,cnt,va;
  cards S[MAX],T[MAX];
  char MR[10];
  int t=1;
  scanf("%d",&cnt);
  for(i=0;i<cnt;i++)
    {
      scanf("%s %d",MR,&va);
      S[i].mark=MR[0];
      T[i].mark=MR[0];
      S[i].num=va;
      T[i].num=va;
    }
  mergS(S,cnt,0,cnt);
  quickS(T,cnt,0,cnt-1);

  for(i=0;i<cnt;i++)
    {
      if(S[i].mark!=T[i].mark)t=0;
    }
  if(t==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<cnt;i++)
    {
      printf("%c %d\n",T[i].mark,T[i].num);
    }
  return 0;
}
