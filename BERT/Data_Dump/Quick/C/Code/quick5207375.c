#include <stdio.h>
#include <stdlib.h>

int partition(int,int);
void Quicksort(int,int);

typedef struct
{
  char patt[2];
  int num;
  int check;
  
} card;

card K[100000];

int main()
{
  int n,i,r,a;
  int count;

  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
    scanf("%s %d",K[i].patt,&K[i].num);
    K[i].check = i;
  }

   Quicksort(0,n-1);

   count=0;

   for(i=0;i<n-1;i++)
   {
     if(K[i].num==K[i+1].num && K[i].check>K[i+1].check) count++;
   }
   /*与えられた入力に対して安定な出力を行っているかを報告*/
   if(count>0) printf("Not stable\n");
   else printf("Stable\n");
   
  for(i=0;i<n;i++)
  {
    printf("%c %d\n",K[i].patt[0],K[i].num);
  
  }

  return 0; 
}


void Quicksort(p,r)
{
  int q;
  if(p<r)
  {
    q=partition(p,r);
    Quicksort(p,q-1);
    Quicksort(q+1,r);
  }

}


int partition(int p,int r)
{
  int x,i,j;
  card d,g;

  x=K[r].num;
  i=p-1;
  for(j=p;j<r;j++)
  {
      if(K[j].num<=x)
      {
          i+=1;
          d=K[i];
          K[i]=K[j];
          K[j]=d;
      }
  }
  g=K[i+1];
  K[i+1]=K[r];
  K[r]=g;
  
  return i+1;
}



