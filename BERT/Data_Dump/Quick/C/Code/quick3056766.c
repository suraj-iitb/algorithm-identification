#include<stdio.h>
#include<stdlib.h>
#define n_max 100001
typedef struct CC{
  char mark;
  int num,f;
}card;

card T[n_max];
int N,i,jud=0;

void swap(card *,card *);
int pt(int ,int );
void quicksort(int ,int );


int main(){
  scanf("%d\n",&N);
  for(i=1;i<=N;i++)
    {
      scanf("%c %d\n",&T[i].mark,&T[i].num);
      T[i].f=i;
    }
		
  quicksort(1,N);
  for(i=2;i<=N;i++)
    if(T[i-1].num==T[i].num && T[i-1].f>T[i].f)
      jud=1;
  puts(jud?"Not stable":"Stable");
  for(i=1;i<=N;i++)
    printf("%c %d\n",T[i].mark,T[i].num);
  return 0;
}


void swap(card *a,card *b)
{
  card temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int pt(int p,int r)
{
  int i,j;
  card c;
  c=T[r];
  i=p-1;
  for(j=p;j<r;j++)
    {
      if(T[j].num <= c.num)
	swap(&T[++i],&T[j]);	
    }
  swap(&T[i+1],&T[r]);
  return i+1;
}

void quicksort(int x,int y)
{
  int z;
  if(x<y){
    z=pt(x,y);
    quicksort(x,z-1);
    quicksort(z+1,y);
  }
}



